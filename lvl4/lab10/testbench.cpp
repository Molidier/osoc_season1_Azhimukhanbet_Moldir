#include "Vbigger.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include <ctime>
#include <iostream>
#include "BittyEmulator.h"
#include "BittyInstructionGenerator.h"
#include <cassert>

#define MAX_SIM_TIME 150
vluint64_t sim_time = 0;

/*BittyEmulator emulator;

extern "C" void evaluate_values(int instr, int out) {
    uint16_t instruction = static_cast<uint16_t>(instr);
    uint16_t alu_out = static_cast<uint16_t>(out);

    uint16_t rx = (instruction & 0xE000) >> 13;
    uint16_t ry = (instruction & 0x1C00) >> 10;

    std::cout << "Register Values: RX=" << emulator.GetRegisterValue(rx) 
              << " RY=" << emulator.GetRegisterValue(ry) << std::endl;

    uint16_t test_res = emulator.Evaluate(instruction);
    if (test_res != alu_out) {
        uint16_t sel = (instruction & 0x001C) >> 2;
        
        std::cout << "ERROR" << std::endl;
        std::cout << "Expected: " << emulator.GetRegisterValue(rx) << std::endl;
        std::cout << "Actual: " << alu_out << std::endl;
    }
    else{
        std::cout<<"GOOD BABE"<<endl;
        std::cout << "Expected: " << emulator.GetRegisterValue(rx) << std::endl;
        std::cout << "Actual: " << alu_out << std::endl;
    }
}

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vbigger* top = new Vbigger;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    BittyInstructionGenerator generator;
    uint16_t instruction = generator.Generate();
    top->d_instr = instruction;

    uint16_t rx = (instruction & 0xE000) >> 13;
    uint16_t ry = (instruction & 0x1C00) >> 10;
    uint16_t sel = (instruction & 0x001C) >> 2;
        

    top->reset = 1;
    top->eval();

    while (!Verilated::gotFinish() && sim_time <= MAX_SIM_TIME) {
        top->clk = !top->clk;
        top->run = 1;
        top->eval();
        if (sim_time == 1) {
            top->run = 1;
            top->reset = 0;
            top->eval();
        }
        if (top->done && top->clk) {
            std::cout << sim_time << std::endl;
            std::cout << "Instruction: " << instruction << std::endl;
            std::cout << "RX=" << rx << " SEL=" << sel << " RY=" << ry << std::endl;
            std::cout<<endl;
            instruction = generator.Generate();
            top->d_instr = instruction;
        }

        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete top;
    exit(0);
}*/


// TESTING WITHOUT DPI
int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vbigger* top = new Vbigger;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    //BittyInstructionGenerator generator;
    uint16_t rx, ry, alu_sel, instruction, format, res_test;
    //generator.Generate();
    BittyEmulator emulator;


    uint16_t pc = 0;


    top->reset = 1;
    top->eval();



    while (!Verilated::gotFinish()  && sim_time<=MAX_SIM_TIME) {
        top->clk = !top->clk;
        top->run=1;
        top->eval();
        if(sim_time==1){
            top->run=1;
            top->reset = 0;
            top->eval();
        }
        if(top->done && top->clk){
            uint16_t instruction = emulator.GetInstructionValue(pc);
            top->run=0;
            top->eval();
            uint16_t reg_num = (instruction & 0xE000)>>13;
            uint16_t reg_val = emulator.GetRegisterValue(reg_num);
            uint16_t next_address = emulator.Evaluate(pc);
            format = (instruction & 0x0003);
            res_test = emulator.GetRegisterValue(reg_num);

            /*if(format== 0 || format == 1){
            }
            else{
                uint16_t prev_instruction = emulator.GetInstructionValue(pc-1);
                uint16_t prev_reg_num = (instruction & 0xE000)>>13;
                res_test = emulator.GetRegisterValue(prev_reg_num);
            }*/
            
            rx = (instruction & 0xE000)>>13;
            ry = (instruction & 0x1C00)>>10;
            alu_sel = (instruction & 0x001C)>>2;

            if(format!=2){
                if(res_test!=top->d_out){
                    std::cout<<"Error"<<endl;
                    cout<<sim_time<<endl;
                    cout<<"Instuction emulator: "<< instruction <<endl;
                    cout<<"Instuction bigger: "<< top->instr <<endl;
                    
                    if(format==0){
                    cout<<rx << " " << alu_sel << " "<< ry<<endl;
                    }
                    else if(format==1){
                        uint16_t immed = (instruction & 0xEFE0) >>5;
                        cout<<rx << " " << immed <<endl;

                    }
                    cout<< "Expected result: "<<res_test<<endl;
                    cout<< "Actual result: "<<top->d_out<<endl;
                    cout<< "Before: "<<reg_val<<". After: "<< res_test<<endl;
                    cout<<endl;
                }
                else{
                    cout<<"GOOD!!"<<endl;
                    cout<<sim_time<<endl;
                    cout<<"Instuction: "<< std::hex << instruction << ". Result: "<<res_test<<endl;
                    cout<<rx << " " << alu_sel << " "<< ry<<endl;
                    cout<< "Before: "<<reg_val<<". After: "<< res_test<<endl;
                    cout<<endl;
                    
                }
            }
            pc = next_address;  
            cout<< "reg0: " << emulator.GetRegisterValue(0x00)<< endl;
    cout<< "reg1: " << emulator.GetRegisterValue(0x01)<< endl;
    cout<< "reg2: " << emulator.GetRegisterValue(0x02)<< endl;
    cout<< "reg3: " << emulator.GetRegisterValue(0x03)<< endl;
    cout<< "reg4: " << emulator.GetRegisterValue(0x04)<< endl;
    cout<< "reg5: " << emulator.GetRegisterValue(0x05)<< endl;
    cout<< "reg6: " << emulator.GetRegisterValue(0x06)<< endl;
    cout<< "reg7: " << emulator.GetRegisterValue(0x07)<< endl;
        }
        
        else{
            
        }
        
        m_trace->dump(sim_time);
        sim_time++;




    }

    /*
    15
    1111

    5-> 0101
     */
    

    m_trace->close();
    delete top;
    exit(0);

}
