#include "Vbitty.h"
#include "verilated.h"

#include <iostream>
#include "BittyEmulator.h"
#include "BittyInstructionGenerator.h"
#include <cassert>

#define MAX_SIM_TIME 10
vluint64_t sim_time = 0;

extern "C" void evaluate_values(int instr, int out) {
    BittyEmulator emulator;
    uint16_t rx, ry, sel;
    uint16_t instruction = (uint16_t) instr;
    uint16_t alu_out = (uint16_t) out;

    uint16_t test_res =  emulator.Evaluate(instruction);
    if(test_res != alu_out){
            rx = (instruction & 0xE000) >> 13;
            ry = (instruction & 0x1C00) >> 10;
            sel = (instruction & 0x001C) >> 2;

            cout<<"Instruction: "<< instruction << endl;
            cout<< rx<<" " <<sel<<" "<< ry<< " " << endl; 
            cout<<"Expexted: " <<test_res<<endl;
            cout<<"Actual: " << alu_out<<endl;

    }
    
}

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
    BittyInstructionGenerator generator;
    uint16_t instruction, rx, ry, sel;
    instruction = generator.Generate();
    top->d_instr = instruction;
    top->clk = 1;
    top->reset = 1;
    top->eval();
    top->reset = 0;
    top->run = 1;

    while (!Verilated::gotFinish()  && sim_time<=MAX_SIM_TIME) {
        top->clk = !top->clk;
        if(top->done){
            top->run = 0;
            top->eval();
            rx = (instruction & 0xE000) >> 13;
            ry = (instruction & 0x1C00) >> 10;
            sel = (instruction & 0x001C) >> 2;

            cout<<"Main instruction: "<< instruction << endl;
            cout<< rx<<" " <<sel<<" "<< ry<< " " << endl;
            instruction = generator.Generate();

            
        }
        top->run = 1;
        top->d_instr = instruction;
        top->eval();

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