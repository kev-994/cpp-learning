#include "register.h"
#include <iostream>
#include <string>



RegisterValue& getRegister(RegisterID destination)
{
    switch (destination)
    {
    case 0:
        return R0;
    case 1:
        return R1;
    case 2:
        return R2;
    case 3:
        return R3;
    case 4:
        return R4;
    case 5:
        return R5;
    case 6:
        return R6;
    case 7:
        return R7;
    case 8:
        return R8;
    case 9:
        return R9;
    case 10:
        return R10;
    case 11:
        return R11;
    case 12:
        return R12;
    case 13:
        return R13;
    case 14:
        return R14;
    case 15:
        return R15;
    }
}

bool executeInstruction(Opcode opcode, RegisterID destination, Immediate immediate)
{
    switch (opcode)
    {
    case LOAD:
        getRegister(destination) = immediate;
        std::cout << "Executing " << "LOAD " << "R" + std::to_string(destination) << ", " << immediate << "\n\n";
        return true;
    case ADD:
        getRegister(destination) += immediate;
        std::cout << "Executing " << "ADD " << "R" + std::to_string(destination) << ", " << immediate << "\n\n";
        return true;
    case SUB:
        getRegister(destination) -= immediate;
        std::cout << "Executing " << "SUB " << "R" + std::to_string(destination) << ", " << immediate << "\n\n";
        return true;
    case PRINT:
        std::cout << "R" + std::to_string(destination) << " = " << getRegister(destination) << "\n\n";
        return true;
    default:
        std::cout << "Instruction includes invalid opcode.\n\n";
        return false;
    }
}

double averageRegisterValue()
{
    return 
        static_cast<double>(static_cast<double>(R0) + R1 + R2 + R3 + R4 + R5 + R6 + R7 + R8 + R9 + R10
        + R11 + R12 + R13 + R14 + R15) / 16;
}

void printStatistics(int instructionsExecuted)
{
    std::cout << "\nStatistics: " << '\n'
        << "Instructions executed: " << instructionsExecuted << '\n'
            <<  "Average register value: " << averageRegisterValue() << '\n';
}