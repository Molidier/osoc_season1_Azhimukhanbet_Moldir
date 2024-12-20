using namespace std;
#include "assemble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

// Maps for instruction names and registers
std::unordered_map<int, std::string> assembleMapInstructionsR = {
    {0, "add"}, {1, "sub"}, {2, "and"}, {3, "or"},
    {4, "xor"}, {5, "shl"}, {6, "shr"}, {7, "cmp"}
};

std::unordered_map<int, std::string> assembleMapInstructionsLS = {
    {0, "ld"}, {1, "st"}
};

std::unordered_map<int, std::string> assembleMapInstructionsI = {
    {0, "addi"}, {1, "subi"}, {2, "andi"}, {3, "ori"},
    {4, "xori"}, {5, "shli"}, {6, "shri"}, {7, "cmpi"}
};

std::unordered_map<int, std::string> assembleMapInstructionsB = {
    {0, "bie"}, {1, "big"}, {2, "bil"}
};

std::unordered_map<int, std::string> assembleMapRegisters = {
    {0, "r0"}, {1, "r1"}, {2, "r2"}, {3, "r3"},
    {4, "r4"}, {5, "r5"}, {6, "r6"}, {7, "r7"}
};

assemble::assemble() {}

void assemble::assembler(const std::string& inputFile, const std::string& outputFile = "outputDef.txt") {
    std::ifstream input(inputFile);
    if (!input) cout<<"Error: Cannot open input file!";

    std::ofstream output;
    if (!outputFile.empty()) output.open(outputFile);

    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        uint16_t instruction;
        ss >> std::hex >> instruction;

        // Extracting format type (last 2 bits)
        uint16_t format = instruction & 0x0003;

        std::string opcode;
        if (format == 0 || format == 3) {  // R-type instruction
            uint16_t rx = (instruction & 0xE000) >> 13;
            uint16_t ry = (instruction & 0x1C00) >> 10;


            std::string reg1 = assembleMapRegisters[rx];
            std::string reg2 = assembleMapRegisters[ry];

            std::stringstream operation;

            if(format == 0){
                uint16_t sel = (instruction & 0x001C) >> 2;
                std::string select = assembleMapInstructionsR[sel];
                operation << select << " " << reg1 << " " << reg2;
            }
            else{
                uint16_t ls = (instruction & 0x0004) >> 2;
                std::string ls_op = assembleMapInstructionsLS[ls];
                operation << ls_op << " " << reg1 << " " << reg2;
            }
            opcode = operation.str();
        } 
        else if (format == 1) {  // I-type instruction
            uint16_t rx = (instruction & 0xE000) >> 13;
            uint16_t immediate = (instruction & 0x1FE0) >> 5;
            uint16_t sel = (instruction & 0x001C) >> 2;

            std::string reg1 = assembleMapRegisters[rx];
            std::string select = assembleMapInstructionsI[sel];

            std::stringstream operation;
            operation << select << " " << reg1 << " " << immediate;
            opcode = operation.str();
        } 
        else if (format == 2) {  // B-type instruction
            uint16_t sel = (instruction & 0x000C) >> 2;
            uint16_t immediate = (instruction & 0xFFF0) >> 4;

            std::string select = assembleMapInstructionsB[sel];

            std::stringstream operation;
            operation << select << " " << immediate;
            opcode = operation.str();
        } 
        else {
            std::cerr << "Error: Unknown instruction format!" << std::endl;
            continue;
        }

        // Output the reconstructed opcode
        if (outputFile.empty()) {
            std::cout << opcode << std::endl;
        } else {
            output << opcode << std::endl;
        }
    }

    input.close();
    if (output.is_open()) output.close();
}
