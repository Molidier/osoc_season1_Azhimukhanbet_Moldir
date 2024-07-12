using namespace std;

#include <vector>
#include <cstdint>

class BittyEmulator
{
    public:
        BittyEmulator();
        uint16_t Evaluate(uint16_t address);
        uint16_t GetRegisterValue(uint16_t reg_num);
        uint16_t GetInstructionValue(uint16_t address);
        void SetRegisterValue(uint16_t reg_num, uint16_t value);
    private:
        std::vector<uint16_t> registers_;
        std::vector<uint16_t> memory_array;
};