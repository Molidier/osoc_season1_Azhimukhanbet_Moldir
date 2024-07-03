
#include "Vbitty.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include <ctime>


#include <iostream>
#include "BittyEmulator.h"
#include "BittyInstructionGenerator.h"
#include <cassert>

#define MAX_SIM_TIME 500
vluint64_t sim_time = 0;

extern "C" void notify_counter_nine_1() {
    std::cout << "S0 BABE!" << std::endl;
}
extern "C" void notify_counter_nine_2() {
    std::cout << "S1 BABE!" << std::endl;
}
extern "C" void notify_counter_nine_3() {
    std::cout << "S2 BABE!" << std::endl;
}
extern "C" void notify_counter_nine_here() {
    std::cout << "HERE BABE" << std::endl;
}

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vbitty* top = new Vbitty;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    BittyEmulator emulator;
    BittyInstructionGenerator generator;
    uint16_t rx, ry, alu_sel, instruction;
    instruction = generator.Generate();
    top->d_instr = instruction;



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
            
            top->run=0;
            top->eval();
            uint16_t reg_num = (instruction & 0xE000)>>13;
            uint16_t reg_val = emulator.GetRegisterValue(reg_num);
            emulator.Evaluate(instruction);
            uint16_t res_test = emulator.GetRegisterValue(reg_num);
            
            rx = (instruction & 0xE000)>>13;
            ry = (instruction & 0x1C00)>>10;
            alu_sel = (instruction & 0x001C)>>2;

            cout<<"Reg->A: "<<top->rega <<". Reg->B: "<<top->regb<<endl;
         
            if(res_test!=top->d_out){
                std::cout<<"Error"<<endl;
                cout<<sim_time<<endl;
                cout<<"Instuction: "<< instruction <<endl;
                cout<<rx << " " << alu_sel << " "<< ry<<endl;
                cout<< "Expected result: "<<res_test<<endl;
                cout<< "Actual result: "<<top->d_out<<endl;
                cout<< "Before: "<<reg_val<<". After: "<< res_test<<endl;
                cout<<endl;
            }
            else{
                cout<<"GOOD!!"<<endl;
                cout<<sim_time<<endl;
                cout<<"Instuction: "<< instruction << ". Result: "<<res_test<<endl;
                cout<<rx << " " << alu_sel << " "<< ry<<endl;
                cout<< "Before: "<<reg_val<<". After: "<< res_test<<endl;
                cout<<endl;
                
            }
            instruction = generator.Generate();
            top->d_instr = instruction;

           
            
        }
        
        else{
            
        }
        m_trace->dump(sim_time);
        sim_time++;

    }
    m_trace->close();
    delete top;
    exit(0);

}
/*
000 110 10011 101 00
*/