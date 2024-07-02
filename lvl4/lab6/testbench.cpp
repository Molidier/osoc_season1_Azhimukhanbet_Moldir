#include "Vbitty.h"
#include "verilated.h"

#include <iostream>
#include "BittyEmulator.h"
#include "BittyInstructionGenerator.h"
#include <cassert>

#define MAX_SIM_TIME 10
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
    BittyEmulator emulator;
    BittyInstructionGenerator generator;
    uint16_t rx, ry, alu_sel, instruction;
    top->clk = !top->clk;
    top->reset = 1;
    top->eval();
    top->run=1;
    top->eval();
    top->eval();
    instruction = generator.Generate();
    top->d_instr = instruction;
    top->eval();


    while (!Verilated::gotFinish()  && sim_time<=MAX_SIM_TIME) {
        top->clk = !top->clk;
        top->eval();
        if(top->done){
            
            top->run=1;
            top->reset = 0;
            
            uint16_t reg_num = (instruction & 0xE000)>>13;
            uint16_t reg_val = emulator.GetRegisterValue(reg_num);
            emulator.Evaluate(instruction);
            uint16_t res_test = emulator.GetRegisterValue(reg_num);
            
            rx = (instruction & 0xE000)>>13;
            ry = (instruction & 0x1C00)>>10;
            alu_sel = (instruction & 0x001C)>>2;

            cout<<"Reg2: "<<top->reg2 <<". Reg->B: "<<top->regb<<endl;
            instruction = generator.Generate();
            top->d_instr = instruction;
            if(res_test!=top->d_out){
                std::cout<<"Error"<<endl;
                cout<<"Instuction: "<< instruction <<endl;
                cout<<rx << " " << alu_sel << " "<< ry<<endl;
                cout<< "Expected result: "<<res_test<<endl;
                cout<< "Actual result: "<<top->d_out<<endl;
                cout<< "Before: "<<reg_val<<". After: "<< res_test<<endl;
                cout<<endl;
            }
            else{
                cout<<"Instuction: "<< instruction << ". Result: "<<res_test<<endl;
                cout<<rx << " " << alu_sel << " "<< ry<<endl;
                cout<< "Before: "<<reg_val<<". After: "<< res_test<<endl;
                cout<<endl;
                
            }
           
            
        }
        
        else{
            cout<<"Nothing babe!"<<endl;
        }
        sim_time++;

    }

    delete top;
    exit(0);

}
/*
101 100 00111 100 10

101 011 0010 000 01

0 10
*/