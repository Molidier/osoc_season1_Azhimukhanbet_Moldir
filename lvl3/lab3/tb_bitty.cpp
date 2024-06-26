#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vbitty.h"
#include <cstdlib>
#include <iostream>
#include <deque>
#include <memory>
#include <ctime>

#define MAX_SIM_TIME 300
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;
vluint64_t cc = 0;

// CPU input interface transaction item class
class CpuInTx {
public:
    uint16_t run;
    uint8_t reset;
    uint8_t carry_in;
    uint16_t d_instr;
    
};

// CPU output interface transaction item class
class CpuOutTx {
public:
    uint16_t reg0;
    uint16_t reg1;
    uint16_t reg2;
    uint16_t reg3;
    uint16_t reg4;
    uint16_t reg5;
    uint16_t reg6;
    uint16_t reg7;
    uint16_t regc;
    uint16_t regs;
    uint8_t done;
    uint16_t d_out;
    uint8_t carry_out;
};

// CPU scoreboard
class CpuScb {
private:
    std::deque<CpuInTx*> in_q;

public:
    void writeIn(CpuInTx *tx){
        in_q.push_back(tx);
    }

    void writeOut(CpuOutTx* tx){
        if(in_q.empty()){
            std::cout << "Fatal Error in CpuScb: empty CpuInTx queue" << std::endl;
            exit(1);
        }

        CpuInTx* in = in_q.front();
        in_q.pop_front();

        // Expected result calculation
        uint16_t expected_d_out = 0;
        uint8_t expected_carry_out = 0;

        // Temporary vars
        uint8_t select = in->d_instr >> 12;
        uint16_t mode = in->d_instr & 0x0004;
        uint16_t b;
        uint16_t ry = ((in->d_instr >> 3) & 0xE000) >> 9;
        uint16_t rx = (in->d_instr & 0xE000) >> 12;
        uint16_t temp;

        switch (ry) {
            case 0: b = tx->reg0; break;
            case 1: b = tx->reg1; break;
            case 2: b = tx->reg2; break;
            case 3: b = tx->reg3; break;
            case 4: b = tx->reg4; break;
            case 5: b = tx->reg5; break;
            case 6: b = tx->reg6; break;
            case 7: b = tx->reg7; break;
            default: b = 0;
        }
        bool start = false;

        if (in->run == 1) {
            start = true;
        } else if (tx->done == 1) {
            start = false;
            cc = 0;
        }

        if (start) {
            if (cc == 0) {
                switch (rx) {
                    case 0: temp = tx->reg0; break;
                    case 1: temp = tx->reg1; break;
                    case 2: temp = tx->reg2; break;
                    case 3: temp = tx->reg3; break;
                    case 4: temp = tx->reg4; break;
                    case 5: temp = tx->reg5; break;
                    case 6: temp = tx->reg6; break;
                    case 7: temp = tx->reg7; break;
                    default: temp = tx->regs;
                }
                if (tx->regs != temp) {
                    std::cout << "Reg S ERROR!" << std::endl;
                    std::cout << "  Expected: regs: " << temp << std::endl;
                    std::cout << "  Actual regs = " << tx->regs << std::endl;
                    std::cout << "  Simtime: " << sim_time << std::endl;
                }   
            }

            if (cc == 1) {
                if (mode == 1) { // Logic operations
                    switch (select) {
                        case 0x0: expected_d_out = ~tx->regs; break;
                        case 0x1: expected_d_out = ~(tx->regs | b); break;
                        case 0x2: expected_d_out = ~tx->regs & b; break;
                        case 0x3: expected_d_out = 0; break;
                        case 0x4: expected_d_out = ~(tx->regs & b); break;
                        case 0x5: expected_d_out = ~b; break;
                        case 0x6: expected_d_out = tx->regs ^ b; break;
                        case 0x7: expected_d_out = tx->regs & ~b; break;
                        case 0x8: expected_d_out = ~tx->regs | b; break;
                        case 0x9: expected_d_out = ~(tx->regs ^ b); break;
                        case 0xA: expected_d_out = b; break;
                        case 0xB: expected_d_out = tx->regs & b; break;
                        case 0xC: expected_d_out = 1; break;
                        case 0xD: expected_d_out = tx->regs | ~b; break;
                        case 0xE: expected_d_out = tx->regs | b; break;
                        case 0xF: expected_d_out = tx->regs; break;
                        default: expected_d_out = 0; break;
                    }

                } else { // Arithmetic operations
                    uint32_t extended_res = 0;
                    switch (select) {
                        case 0x0: extended_res = tx->regs; break;
                        case 0x1: extended_res = tx->regs | b; break;
                        case 0x2: extended_res = (tx->regs | (~b)) & 0xFFFF; break;
                        case 0x3: extended_res = -1; break;
                        case 0x4: extended_res = tx->regs | (tx->regs & ~b); break;
                        case 0x5: extended_res = ((tx->regs | b) + (tx->regs & ~b) + in->carry_in) & 0xFFFF; break;
                        case 0x6: extended_res = (tx->regs - b - 1) ; break;
                        case 0x7: extended_res = tx->regs & ~b; break;
                        case 0x8: extended_res = tx->regs + (tx->regs & b) + in->carry_in; break;
                        case 0x9: extended_res = tx->regs + b + in->carry_in; break;
                        case 0xA: extended_res = (tx->regs | (~b) & 0xFFFF) + (tx->regs & b) + in->carry_in; break;
                        case 0xB: extended_res = tx->regs & b; break;
                        case 0xC: extended_res = tx->regs + tx->regs + in->carry_in; break;
                        case 0xD: extended_res = (tx->regs | b) + tx->regs + in->carry_in; break;
                        case 0xE: extended_res = (tx->regs | (~b) & 0xFFFF) + tx->regs + in->carry_in; break;
                        case 0xF: extended_res = tx->regs + in->carry_in; break;
                        default: extended_res = 0; break;
                    }      
                    expected_d_out = extended_res & 0xFFFF;
                    expected_carry_out = ((extended_res ) >> 16) & 0x1;
                }
                if (expected_d_out != tx->d_out || expected_carry_out != tx->carry_out) {
                    std::cout << "CpuScb mismatch:" << std::endl;
                    std::cout << "  Expected: a: " << tx->regs << std::endl;
                    std::cout << "  Expected: b: " << b << std::endl;
                    std::cout << "  Expected: d_out: " << expected_d_out << std::endl;
                    std::cout << "  Expected: carry_out: " << expected_carry_out << std::endl;
                    std::cout << "  Actual d_out = " << tx->d_out << std::endl;
                    std::cout << "  Actual carry_out = " << tx->carry_out << std::endl;
                    std::cout << "  Simtime: " << sim_time << std::endl;
                }
            }
        } else if (tx->done == 1) {
            cc = 0;
        }
        cc = cc + 1;
    }
};

// CPU input driver
class CpuInDrv {
private:
    Vbitty* dut;
    std::deque<CpuInTx*>* q;

public:
    CpuInDrv(Vbitty* dut, std::deque<CpuInTx*>* q){
        this->dut = dut;
        this->q = q;
    }

    void drive(){
        if(q->empty())
            return;

        CpuInTx* tx = q->front();
        q->pop_front();

        dut->run = tx->run;
        dut->reset = tx->reset;
        dut->carry_in = tx->carry_in;
        dut->d_instr = tx->d_instr;

        delete tx;
    }
};

// CPU input monitor
class CpuInMon {
private:
    Vbitty* dut;
    CpuScb* scb;

public:
    CpuInMon(Vbitty* dut, CpuScb* scb){
        this->dut = dut;
        this->scb = scb;
    }

    void monitor(){
        CpuInTx* tx = new CpuInTx();

        tx->run = dut->run;
        tx->reset = dut->reset;
        tx->carry_in = dut->carry_in;
        tx->d_instr = dut->d_instr;

        scb->writeIn(tx);
    }
};

// CPU output monitor
class CpuOutMon {
private:
    Vbitty* dut;
    CpuScb* scb;

public:
    CpuOutMon(Vbitty* dut, CpuScb* scb){
        this->dut = dut;
        this->scb = scb;
    }

    void monitor(){
        CpuOutTx* tx = new CpuOutTx();

        tx->reg0 = dut->reg0;
        tx->reg1 = dut->reg1;
        tx->reg2 = dut->reg2;
        tx->reg3 = dut->reg3;
        tx->reg4 = dut->reg4;
        tx->reg5 = dut->reg5;
        tx->reg6 = dut->reg6;
        tx->reg7 = dut->reg7;
        tx->regc = dut->regc;
        tx->regs = dut->regs;
        tx->d_out = dut->d_out;
        tx->carry_out = dut->carry_out;

        scb->writeOut(tx);
    }
};

// Random CPU input transaction generator
CpuInTx* rndCpuInTx(){
    CpuInTx* tx = new CpuInTx();

    tx->run = rand() % 2;
    tx->reset = rand() % 2;
    tx->carry_in = rand() % 2;
    tx->d_instr = rand() & 0xFFFF;

    return tx;
}

int main(int argc, char** argv, char** env) {
    srand(time(0));
    Verilated::commandArgs(argc, argv);
    Vbitty* dut = new Vbitty;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // Simulation setup
    std::deque<CpuInTx*> cpu_in_q;
    CpuScb* cpu_scb = new CpuScb();
    CpuInDrv* cpu_in_drv = new CpuInDrv(dut, &cpu_in_q);
    CpuInMon* cpu_in_mon = new CpuInMon(dut, cpu_scb);
    CpuOutMon* cpu_out_mon = new CpuOutMon(dut, cpu_scb);

    while (sim_time < MAX_SIM_TIME) {
        dut->clk ^= 1;
        dut->eval();

        if(sim_time >= VERIF_START_TIME) {
            cpu_in_drv->drive();
            cpu_in_mon->monitor();
            cpu_out_mon->monitor();
        }

        m_trace->dump(sim_time);
        sim_time++;

        if((sim_time % 2) == 0 && (sim_time >= VERIF_START_TIME)) {
            cpu_in_q.push_back(rndCpuInTx());
        }
    }

    m_trace->close();
    delete dut;
    delete cpu_scb;
    delete cpu_in_drv;
    delete cpu_in_mon;
    delete cpu_out_mon;

    return 0;
}
