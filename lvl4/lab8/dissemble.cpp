#include "dissemble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> dissembleMapInstructionsR = {
    {"add", 0}, {"sub", 1}, {"and", 2}, {"or", 3},
    {"xor", 4}, {"shl", 5}, {"shr", 6}, {"cmp", 7}
};

std::unordered_map<std::string, int> dissembleMapInstructionsI = {
    {"addi", 0}, {"subi", 1}, {"andi", 2}, {"ori", 3},
    {"xori", 4}, {"shli", 5}, {"shri", 6}, {"cmpi", 7}
};

std::unordered_map<std::string, int> dissembleMapInstructionsB = {
    {"bie", 0}, {"big", 1}, {"bil", 2}
};

std::unordered_map<std::string, int> dissembleMapRegisters = {
    {"r0", 0}, {"r1", 1}, {"r2", 2}, {"r3", 3},
    {"r4", 4}, {"r5", 5}, {"r6", 6}, {"r7", 7}
};

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> operations;
    std::string operation;
    std::istringstream operationStream(str);
    while (std::getline(operationStream, operation, delimiter)) {
        operations.push_back(operation);
    }
    return operations;
}

Dissembler::Dissembler() {
}

void Dissembler::dissemble(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    if (!input) {
        std::cerr << "Error: Cannot open input file!" << std::endl;
        return;
    }

    std::ofstream output;
    if (!outputFile.empty()) output.open(outputFile);

    uint16_t format = 0;
    uint16_t op = 0;
    std::string line;
    while (std::getline(input, line)) {
        std::vector<std::string> operation = split(line, ' ');
        if (dissembleMapInstructionsR.count(operation[0])) {
            uint16_t reg1 = dissembleMapRegisters[operation[1]];
            uint16_t reg2 = dissembleMapRegisters[operation[2]];
            uint16_t select = dissembleMapInstructionsR[operation[0]];

            uint16_t rx = (reg1 << 13) & 0xE000;
            uint16_t ry = (reg2 << 10) & 0x1C00;
            uint16_t sel = (select << 2) & 0x001C;
            format = 0;

            op = rx + ry + sel + format;
        } else if (dissembleMapInstructionsI.count(operation[0])) {
            uint16_t reg1 = dissembleMapRegisters[operation[1]];
            uint16_t reg2 = std::stoi(operation[2]);
            uint16_t select = dissembleMapInstructionsI[operation[0]];

            uint16_t rx = (reg1 << 13) & 0xE000;
            uint16_t ry = (reg2 << 5) & 0x1FE0;
            uint16_t sel = (select << 2) & 0x001C;
            format = 1;

            op = rx + ry + sel + format;
        } else if (dissembleMapInstructionsB.count(operation[0])) {
            uint16_t select = dissembleMapInstructionsB[operation[0]];
            uint16_t immediate = std::stoi(operation[1]);

            uint16_t sel = (select << 2) & 0x000C;
            uint16_t immed = (immediate << 4) & 0xFFF0;
            format = 2;

            op = sel + immed + format;
        } else {
            std::cerr << "Error: Unknown instruction " << operation[0] << std::endl;
            continue;
        }

        std::stringstream ss;
        ss << std::hex << op;
        std::string opcode = ss.str();
        if (outputFile.empty()) {
            std::cout << opcode << std::endl;
        } else if (output.is_open()) {
            output << opcode << std::endl;
        }
    }

    input.close();
    if (output.is_open()) {
        output.close();
    }
}
