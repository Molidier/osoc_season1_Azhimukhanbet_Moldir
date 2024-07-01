#include "BittyInstructionGenerator.h"
#include <cstdlib>
#include <cstdint>

extern "C" uint16_t BittyInstructionGenerator::Generate(){
    return rand()%0xFFFF;
}