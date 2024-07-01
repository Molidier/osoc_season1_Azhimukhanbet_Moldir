#include "Vbitty.h"
#include "verilated.h"

#include <iostream>
#include "BittyEmulator.h"
#include "BittyInstructionGenerator.h"
#include <cassert>

#define MAX_SIM_TIME 10
vluint64_t sim_time = 0;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vbitty* top = new Vbitty;
    BittyEmulator emulator;
    BittyInstructionGenerator generator;

    while (!Verilated::gotFinish()  && sim_time<=MAX_SIM_TIME) {
        top->clk = !top->clk;
        uint16_t instruction = generator.Generate();
        top->d_instr = instruction;
        top->eval();
        uint16_t reg_num = (instruction & 0xE000)>>13;
        uint16_t reg_val = emulator.GetRegisterValue(reg_num);
        emulator.Evaluate(instruction);
        uint16_t res_test = emulator.GetRegisterValue(reg_num);
        sim_time++;
        if(res_test!=top->d_out){
            std::cout<<"Error"<<endl;
            cout<<"Instuction: "<< instruction <<endl;
            cout<< "Expected result: "<<res_test<<endl;
            cout<< "Actual result: "<<top->d_out<<endl;
            cout<< "Before: "<<reg_val<<". After: "<< res_test;
        }
        else{
            cout<<"Instuction: "<< instruction << ". Result: "<<res_test<<endl;
        }
    }

    delete top;
    exit(0);
}
/*
101 100 00111 100 10

101 011 0010 000 01

0 10
*/