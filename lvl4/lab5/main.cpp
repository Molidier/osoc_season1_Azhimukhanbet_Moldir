#include <iostream>
#include "BittyEmulator.h"
#include <cassert>

int main()
{
   BittyEmulator emulator;
   /* emulator.SetRegisterValue(0, 5);
    emulator.SetRegisterValue(4, 2);

    // Test instruction 0x1234 (replace with actual instruction value)
    uint16_t testInstruction = 0x2800;
    cout<< emulator.Evaluate(testInstruction)<<endl;

    // Check register values after execution
    // Assuming instruction 0x1234 modifies register 0
    uint16_t regValue = emulator.GetRegisterValue(0);

    // Manually pre-calculate expected value.
    uint16_t expected_value = 20;
    std::cout << "Register 0 value: " << regValue << std::endl;
    assert(regValue == expected_value);*/

    emulator.SetRegisterValue(1, 10);
    emulator.SetRegisterValue(2, 67);


    uint16_t test2 = 0x2800;
    /*
    001 010 00000 000 00 
    */

    cout<< emulator.Evaluate(test2)<<endl;
    //emulator.Evaluate(test2);
    uint16_t reg_test2 = emulator.GetRegisterValue(1);
    uint16_t exp2 = 77;
    std::cout << "Register 1 value: " << reg_test2 << std::endl;
    assert(reg_test2 == exp2);


    return 0;
}

