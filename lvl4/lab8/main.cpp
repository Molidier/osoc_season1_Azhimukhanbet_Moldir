using namespace std;

#include "assemble.h"
#include "dissemble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

//reference to the string object
// const -> original string is not modified


int main(int argc, char* argv[]){
   // if(argc < 3) cout<<"Error: Input file and action (-a or -d) required!");
    
    string inputFile;
    string outputFile;
    bool assembleFlag = false;
    bool disassembleFlag = false;
    assemble assembler;
    Dissembler dissembler;
    bool outFileFlag = false;

    for (int i = 0; i<argc;i++){
        string val = argv[i];
        if(val == "-i"){
            if(i+1<argc) inputFile = argv[++i];
            else cout<<"Error: No input file"<<endl;
        }
        else if(val == "-o"){
            outFileFlag = true;
            if(i+1<argc) outputFile = argv[++i];
            else cout<<"Error: No output file"<<endl;

        }
        else if(val == "-a"){
            assembleFlag = true;
        }
        else if(val == "-d"){
            disassembleFlag = true;
        }
    }

    if (inputFile.empty()) cout<<"Error: Input file is requiered!"<<endl;
    if(!assembleFlag &&!disassembleFlag) cout<< "Error: Either -a or -d flag must be specified!" << endl;

    if(assembleFlag){
        assembler.assembler(inputFile, outputFile);
    }
    else if(disassembleFlag){
        dissembler.dissemble(inputFile, outputFile);
    }

    if(!outFileFlag){
        ifstream printFile("outputDef.txt");
        if(!printFile){
            cerr<<"Error: Cannot open default out file"<<endl;
        } 
        else{
            string line;
            while(getline(printFile, line)){
                cout<<line<<endl;
            }
        } 
        printFile.close();
    }
    return 0;
}