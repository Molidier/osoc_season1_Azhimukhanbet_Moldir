using namespace std;
#include "BittyEmulator.h"
#include <iostream>
#include <fstream>
#include <vector>



        BittyEmulator::BittyEmulator() : registers_(16,0){
            std:: ifstream infile; 
            infile.open("instructions.txt", std::ios::in);

            uint16_t instr;
            
            if(infile.is_open()){
                while(infile >> std::hex >> instr){
                    cout<<"Instruction pushed: "<<instr<<endl;
                    memory_array.push_back(instr);

                }
                infile.close();
            }
            else{
                cerr<<"Error opening file"<<endl;
            }
        }
        /*
        step instruction -> compare PC -> last computed value 
         */
        uint16_t BittyEmulator::Evaluate(uint16_t address){
            uint16_t instruction = memory_array[address];
            uint16_t format = (instruction & 0x0003);
            uint16_t rx = (instruction & 0xE000)>>13;
            uint16_t ry, in_b;
            if(format==0){
                ry = (instruction & 0x1C00)>>10;
                in_b = registers_[ry];
                cout<<"Normal"<<endl;
            }
            else if(format==1){
                cout<<"Immidiate"<<endl;
                in_b = (instruction & 0x1FE0)>>5;

            }
            else if(format==2){
                uint16_t branch_cond = (instruction & 0x000C)>>2;
                uint16_t branch_immid = (instruction & 0xFFF0)>>4;
                cout<<"Branch"<<endl;
                uint16_t prev_instruction = memory_array[address-1];
                uint16_t prev_val_reg = (prev_instruction & 0xE000)>>13;
                uint16_t compare_value = registers_[prev_val_reg];
                switch (branch_cond)
                {
                case 0: if(compare_value == 0){
                    return branch_immid;
                    }
                    break;
                case 1: if(compare_value == 1){
                    return branch_immid;
                    }
                    break;
                case 2: if(compare_value == 2){
                    return branch_immid;
                    }
                    break;
                default: return address + 1;
                    break;
                }

            }
            else cout<<"CRINGE"<<endl;
            uint16_t alu_sel = (instruction & 0x001C)>>2;
            
            if(format!=2){
            uint16_t result;
            
            switch (alu_sel)
            {
            case 0x0: result = registers_[rx] + in_b; break;
            case 0x1: result = registers_[rx] - in_b; break;
            case 0x2: result = registers_[rx] & in_b; break;
            case 0x3: result = registers_[rx] | in_b; break;
            case 0x4: result = registers_[rx] ^ in_b; break;
            case 0x5: result = registers_[rx] << in_b; 
                cout<<registers_[rx] << " --- " << in_b<<endl;
            break;
            case 0x6: result = registers_[rx] >> in_b; break;
            case 0x7: 
            if(registers_[rx] == in_b){
                result = 0; 
            }
            else if(registers_[rx] > in_b){
                result = 1; 
            }
            else {
                result = 2; 
            }
            break;
            default: result = 0;
                break;
            }

            registers_[rx] = result;}
            return address + 1;



        }

        extern "C" uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num){
            return registers_[reg_num];
        }

        uint16_t BittyEmulator::GetInstructionValue(uint16_t address){
            return memory_array[address];
        }

        void BittyEmulator::SetRegisterValue(uint16_t reg_num, uint16_t value){
            registers_[reg_num] = value;
        }
    




