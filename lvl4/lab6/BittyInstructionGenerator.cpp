#include "BittyInstructionGenerator.h"
#include <cstdlib>

extern "C" unit16_t BittyInstructionGenerator::Generate(){
    return rand()%0xFFFF;
}