using namespace std;

#include "assemble.cpp"
#include "dissemble.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

//reference to the string object
// const -> original string is not modified


int main(int argc, char* argv[]){
   // if(argc < 3) showError("Error: Input file and action (-a or -d) required!");
    
    string inputFile;
    string outputFile;
    bool assembleFlag = false;
    bool disassembleFlag = false;
    assemble assembler;
    dissemble dissembler;
    bool outFileFlag = false;

    for (int i = 0; i<argc;i++){
        string val = argv[i];
        if(val == "-i"){
            if(i+1<argc) inputFile = argv[++i];
            else showError("Error: No input file");
        }
        else if(val == "-o"){
            outFileFlag = true;
            if(i+1<argc) outputFile = argv[++i];
            else showError("Error: No output file");

        }
        else if(val == "-a"){
            assembleFlag = true;
        }
        else if(val == "-d"){
            disassembleFlag = true;
        }
    }

    if (inputFile.empty()) showError("Error: Input file is requiered!");
    if(!assembleFlag &&!disassembleFlag) showError("Error: Either -a or -d flag must be specified!");

    if(assembleFlag){
        assembler.assembler(inputFile, outputFile);
    }
    else if(disassembleFlag){
        dissembler.dissembler(inputFile, outputFile);
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