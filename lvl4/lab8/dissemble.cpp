
//using namespace std;
#include "dissemble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>


unordered_map <string, int> dissembleMapInstructionsR = {
    {"add", 0},
    {"sub", 1},
    {"and", 2},
    {"or", 3},
    {"xor", 4},
    {"shl", 5},
    {"shr", 6},
    {"cmp", 7}
};

unordered_map <string, int> dissembleMapInstructionsI = {
    {"addi", 0},
    {"subi", 1},
    {"andi", 2},
    {"ori", 3},
    {"xori", 4},
    {"shli", 5},
    {"shri", 6},
    {"cmpi", 7}
};
unordered_map <string, int> dissembleMapInstructionsB = {
    {"bie", 0},
    {"big", 1},
    {"bil", 2},
};
unordered_map<string, int> dissembleMapRegisters = {
    {"r0", 0},
    {"r1", 1},
    {"r2", 2},
    {"r3", 3},
    {"r4", 4},
    {"r5", 5},
    {"r6", 6},
    {"r7", 7}
};



vector<string> split(const string& str, char delimiter){
    vector<string> operations;
    string operation;
    istringstream operationStream(str);
    while(getline(operationStream, operation, delimiter)){
        operations.push_back(operation);
    }

    return operations;
    
}

dissemble::dissemble() {
}

void dissemble::dissembler(const string& inputFile, const string& outputFile = "outputDef.txt"){
    ifstream input(inputFile);
    if(!input) showError("Error: Cannot open input file!");
    
    ofstream output;
    if(!outputFile.empty()) output.open(outputFile);

    uint16_t format = 0;
    uint16_t op = 0;
    string line;
    while(getline(input, line)){
        vector<string> operation = split(line, ' ');
        if(dissembleMapInstructionsR.count(operation[0])){
        uint16_t reg1 = dissembleMapRegisters[operation[1]];
        uint16_t reg2 = dissembleMapRegisters[operation[2]];
        uint16_t select = dissembleMapInstructionsR[operation[0]];

        uint16_t rx = (reg1 << 13) & 0xE000;

        uint16_t ry = (reg2 << 10) & 0x1C00;
        uint16_t sel = (select << 2) & 0x001C;
        
        op = rx + ry + sel + format;
        }
        else if(dissembleMapInstructionsI.count(operation[0])){
        uint16_t reg1 = dissembleMapRegisters[operation[1]];
        uint16_t reg2 = stoi(operation[2]);
        uint16_t select = dissembleMapInstructionsI[operation[0]];

        uint16_t rx = (reg1 << 13) & 0xE000;

        uint16_t ry = (reg2 << 5) & 0x1FE0;
        uint16_t sel = (select << 2) & 0x001C;
        format = 1;    
        
        op = rx + ry + sel + format;   
        }
        else{
            uint16_t select = dissembleMapInstructionsB[operation[0]];
            uint16_t immediate = stoi(operation[2]);

            uint16_t sel = (select << 2) & 0x000C;
            uint16_t immed = (select << 4) & 0xFFF0;
            format = 2; 

            op = sel + immed + format;
            
        }
        


        stringstream ss;
        ss<<hex << op;
        string opcode = ss.str();
        if (outputFile.empty()) {
            std::cout << opcode << std::endl;
        }
        else{
            output << opcode << endl;
        }     
    }
}