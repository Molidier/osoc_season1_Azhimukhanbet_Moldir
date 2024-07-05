
#include "BittyInstructionGenerator.h"
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

extern "C" uint16_t BittyInstructionGenerator::Generate(){
    int count;
    uint16_t instruction;
    std::cout<<"Write number of instructions";
    std::cin>>count;

    std:: ofstream file; 
    file.open("instructions.txt", std::ios::out);

    if(file.is_open()){
        for(int i=0;i<count;i++){
            //hex convertation
            instruction = rand()%0xFFFF;

            //std:: string hex_instr = ss.str();
            //write into file
            file<< std::hex << std::setw(256)<< std:: setfill('0')<<std::endl;
        }
    }
    file.close();
    
}