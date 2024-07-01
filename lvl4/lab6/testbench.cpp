#include "Vbitty.h"
#include "verilated.h"

#include <iostream>
#include "BittyEmulator.h"
#include "BittyInstructionGenerator.h"
#include <cassert>

#define MAX_SIM_TIME 100
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
        uint16_t res_test = emulator.Evaluate(instruction);
        if(res_test!=top->d_out){
            std::cout<<"Error";
        }
        else{
            cout<<"IT WORKS!!";
        }
    }

    delete top;
    exit(0);
}
