#include "instruction.h"
#include <iostream>

namespace cpu
{
    unsigned int instruction{};
    
    namespace
    {   
        unsigned int getOpcode()
        {    
            return (instruction >> 28) & 0xF;
        }
        unsigned int getCondition()
        {   
            return (instruction >> 24) & 0xF;
        }
        unsigned int getDest()
        {   
            return (instruction >> 20) & 0xF;
        }
        unsigned int getSourceOne()
        {   
            return (instruction >> 16) & 0xF;
        }
        unsigned int getSourceTwo()
        {   
            return (instruction >> 12) & 0xF;
        }
        unsigned int getFlag()
        {   
            return (instruction >> 8) & 0xF;
        }
        unsigned int getImm()
        {   
            return instruction & 0xFF;
        }

        constexpr unsigned int reservedRegister{15};
        
        // supported Opcodes
        constexpr unsigned int nopInstruction  {0};
        constexpr unsigned int addInstruction  {1};
        constexpr unsigned int subInstruction  {2};
        constexpr unsigned int mulInstruction  {3};
        constexpr unsigned int loadInstruction {4};
        constexpr unsigned int storeInstruction{5};
        constexpr unsigned int andInstruction  {6};
        constexpr unsigned int orInstruction   {7};

        // condition codes
        constexpr unsigned int alwaysCondition {0};
        constexpr unsigned int equalCondition  {1};
        constexpr unsigned int nequalCondition {2};
        constexpr unsigned int gthanConditon   {3};
        constexpr unsigned int lthanCondition  {4};
    }

    bool validOpcode()
    {
        if (getOpcode() > 7)
            return false;
        return true;
    }

    bool validCondition()
    {
        if (getCondition() > 4)
            return false;
        return true;
    }

    bool validInstruction()
    {
        if (!validOpcode())
            return false;
        
        if(!validCondition())
            return false;

        if((getOpcode() == nopInstruction) && !((instruction & 0x0FFFFFFF) == 0)) // NOP should contain no non-zero fields after opcode
            return false;
        
        if ((getOpcode() == loadInstruction) || (getOpcode() == storeInstruction)) // LOAD or STORE uses the same register for the destination and source register 1.
        {    
            if (getDest() == getSourceOne())
                return false;
        }    
        
        if ((getFlag() & 0b1000) != 0) // A privileged instruction is invalid unless its condition code is Always.
        {    
            if (getCondition() != alwaysCondition)
                return false;
        }
        
        switch (getOpcode()) // ADD, SUB, MUL, AND, or OR uses register 15 as any operand.
        {
        case 1:
            [[fallthrough]];
        case 2:
            [[fallthrough]];
        case 3:
            [[fallthrough]];
        case 6:
            [[fallthrough]];
        case 7:
            if ((getDest() == reservedRegister) || (reservedRegister) || (getSourceTwo() == reservedRegister))  
                return false;  
        default:
            break;
        }
        
        return true;
    }
        
    void printInstructionName()
    {
        std::cout << "Instruction ";

        switch(getOpcode())
        {
        case nopInstruction:
            std::cout << "NOP\n";
            return;
        case addInstruction:
            std::cout << "ADD\n";
            return;
        case subInstruction:
            std::cout << "SUB\n";
            return;
        case mulInstruction:
            std::cout << "MUL\n";
            return;
        case loadInstruction:
            std::cout << "LOAD\n";
            return;
        case storeInstruction:
            std::cout << "STORE\n";
            return;
        case andInstruction:
            std::cout << "AND\n";
            return;
        case orInstruction:
            std::cout << "OR\n";
            return;
        default: 
            std::cout << "Unknown\n";
            return;
        }

    }

    void printCondition()
    {
        std::cout << "Condition: ";

        switch(getCondition())
        {
        case alwaysCondition:
            std::cout << "Always\n";
            return;
        case equalCondition:
            std::cout << "Equal\n";
            return;
        case nequalCondition:
            std::cout << "Not equal\n";
            return;
        case gthanConditon:
            std::cout << "Greater than\n";
            return;
        case lthanCondition:
            std::cout << "Less than\n";
            return;
        default: 
            std::cout << "Unknown\n";
            return;
        }
    }

    void printRegisters()
    {
        std::cout << "Destination register: R" << getDest() << '\n';
        std::cout << "Source register 1: R" << getSourceOne() << '\n';
        std::cout << "Source register 2: R" << getSourceTwo() << '\n';
    }

    void printFlags()
    {
        std::cout << "Flags: \n";
        bool updateStatus {bool ((getFlag() >> 0) & 1)};
        bool signedOperation {bool ((getFlag() >> 1) & 1)};
        bool saturatedOperation {bool ((getFlag() >> 2) & 1)};
        bool privilegedOperation {bool ((getFlag() >> 3) & 1)};

        std::cout << "Update status: " << ((updateStatus) ? "yes\n" : "no\n");
        std::cout << "Signed operation: " << ((signedOperation) ? "yes\n" : "no\n");
        std::cout << "Saturated operation: " << ((saturatedOperation) ? "yes\n" : "no\n");
        std::cout << "Privileged operation: " << ((privilegedOperation) ? "yes\n" : "no\n");
    }
    
    void printDecodedInstruction()
    {
        printInstructionName();
        printCondition();
        printRegisters();
        std::cout << "Immediate value: " << getImm() << "\n\n";

        printFlags();
        std::cout << '\n';

        std::cout << "Instruction is " << ((validInstruction()) ? "valid\n" : "invalid\n");


    }
    
}

/*
Minor effieciency improvement: 
const unsigned int opcode{getOpcode()};
const unsigned int condition{getCondition()};
*/