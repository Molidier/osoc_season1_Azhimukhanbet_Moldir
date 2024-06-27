using namespace std;
#include "BittyEmulator.h"



        BittyEmulator::BittyEmulator() : registers_(16,0){}

        uint16_t BittyEmulator::Evaluate(uint16_t instruction){
            uint16_t rx = instruction & 0xE000;
            uint16_t ry = (instruction & 0x1C00)>>10;
            uint16_t alu_sel = (instruction & 0x001C)>>2;

            uint16_t result;

            switch (alu_sel)
            {
            case 0x0: result = registers_[rx] + registers_[ry]; break;
            case 0x1: result = registers_[rx] - registers_[ry]; break;
            case 0x2: result = registers_[rx] | registers_[ry]; break;
            case 0x3: result = registers_[rx] & registers_[ry]; break;
            case 0x4: result = registers_[rx] ^ registers_[ry]; break;
            case 0x5: result = registers_[rx] << registers_[ry]; break;
            case 0x6: result = registers_[rx] >> registers_[ry]; break;
            case 0x7: 
            if(registers_[rx] == registers_[ry]){
                result = 0; 
            }
            else if(registers_[rx] > registers_[ry]){
                result = 1; 
            }
            else {
                result = 2; 
            }
            break;
            default: result = 0;
                break;
            }

            registers_[rx] = result;
            return result;



        }

        uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num){
            return registers_[reg_num];
        }
    




