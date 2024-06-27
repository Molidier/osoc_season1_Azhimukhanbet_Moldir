#include <iostream>
#include "BittyEmulator.h"
#include <cassert>

int main()
{
    BittyEmulator emulator;

    // Test instruction 0x1234 (replace with actual instruction value)
    uint16_t testInstruction = 0x1234;
    emulator.Evaluate(testInstruction);

    // Check register values after execution
    // Assuming instruction 0x1234 modifies register 0
    uint16_t regValue = emulator.GetRegisterValue(0);
/*
1234
000 100 10001 101 00


 */
    // Manually pre-calculate expected value.
    uint16_t expected_value = 0;
    std::cout << "Register 0 value: " << regValue << std::endl;
    assert(regValue == expected_value);


    return 0;
}

