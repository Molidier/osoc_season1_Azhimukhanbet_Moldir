//using namespace std;
#include "assemble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

void showError(const string& error){
    cerr<< error <<endl; //print error message
    exit(EXIT_FAILURE);//exiting with a failure status
}



unordered_map<int, string> assembleMapInstructions = {
    {0, "add"},
    {1, "sub"},
    {2, "and"},
    {3, "or"},
    {4, "xor"},
    {5, "shl"},
    {6, "shr"},
    {7, "cmp"}
};

unordered_map<int, string> assembleMapRegisters = {
    {0, "r0"},
    {1, "r1"},
    {2, "r2"},
    {3, "r3"},
    {4, "r4"},
    {5, "r5"},
    {6, "r6"},
    {7, "r7"}
};


assemble::assemble() {
}

void assemble::assembler(const string& inputFile, const string& outputFile = "outputDef.txt"){
    ifstream input(inputFile);
    if(!input) showError("Error: Cannot open input file!");
    
    ofstream output;
    if(!outputFile.empty()) output.open(outputFile);

    string line;
    while(getline(input, line)){
        stringstream ss(line);
        uint16_t instruction;
        ss>>hex>>instruction;

        uint16_t rx = (instruction & 0xE000) >> 13;
        uint16_t ry = (instruction & 0x1C00) >> 10;
        uint16_t sel = (instruction & 0x001C) >> 2;

        string reg1 = assembleMapRegisters[rx];
        string reg2 = assembleMapRegisters[ry];
        string select = assembleMapInstructions[sel];

        stringstream operation;
        operation<< select << " " << reg1 <<" " << reg2;
        string opcode = operation.str();
        if (outputFile.empty()) {
            std::cout << opcode << std::endl;
        }
        else{
            output << opcode << endl;
        }     
    }
}