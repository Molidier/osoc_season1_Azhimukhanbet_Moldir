
#include "BittyInstructionGenerator.h"
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

extern "C" void BittyInstructionGenerator::Generate(){
    int count;
    uint16_t instruction;
    std::cout<<"Write number of instructions";
    std::cin>>count;

    std:: ofstream file; 
    file.open("instructions.txt", std::ios::out);

    if(file.is_open()){
        for(int i=0;i<count;i++){
            instruction = rand()%0xFFFF;
            //instruction = instruction & 0xFFFD;
            uint16_t format = (instruction & 0x0003);
            if(format==0){
                instruction = instruction & 0xFC1F;
            }
            else if(format==3){
                instruction = instruction & 0xFFFE;
            }
                 
            std::cout<<"Instruction generated: "<<instruction<<std::endl;

            file<< std::hex << std::setw(4)<< std:: setfill('0')<< instruction<<std::endl;
        }
    }
    else{
        std::cerr << "Error opening instruction.txt file" << std::endl;
    }
    file.close();
    
}