
//using namespace std;
#include "dissemble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>


unordered_map <string, int> dissembleMapInstructions = {
    {"add", 0},
    {"sub", 1},
    {"and", 2},
    {"or", 3},
    {"xor", 4},
    {"shl", 5},
    {"shr", 6},
    {"cmp", 7}
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

    string line;
    while(getline(input, line)){
        vector<string> operation = split(line, ' ');



        uint16_t reg1 = dissembleMapRegisters[operation[1]];
        uint16_t reg2 = dissembleMapRegisters[operation[2]];
        uint16_t select = dissembleMapInstructions[operation[0]];

        uint16_t rx = (reg1 << 13) & 0xE000;

        uint16_t ry = (reg2 << 10) & 0x1C00;
        uint16_t sel = (select << 2) & 0x001C;

        /*cout<<reg1<< " " <<rx<<endl;
        cout<<reg2<<" " << ry<<endl;
        cout<<select<<" " <<sel<<endl;*/

        uint16_t op = rx + ry + sel;
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