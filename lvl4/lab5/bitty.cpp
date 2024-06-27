using namespace std;

class BittyEmulator
{
    public:
        BittyEmulator();
        uint16_t Evaluate(uint16_ instruction);
        unit16_t GetRegisterValue(unit16_t reg_num);
    
    private:
        vector<uint16_t> registers_;  
    
    Evaluate(uint16_t instruction){

        uint16_t rx = instruction & 0xE000;
        uint16_t ry = (instruction & 0x1C00)>>10;
        uint16_t alu_sel = (instruction & 0x001C)>>2;

    }
     
    GetRegisterValue(unit16_t reg_num){
        
    }
}

