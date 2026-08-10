// 8 bit CPU Execution Unit
#include "execution.h"
#include "alu_implementation.h"
#include <iostream>
#include <limits>
#include <cstdint>

int main()
{
    CPU cpu {};

    while (!cpu.halted)
    {
        
        Instruction instruction{};

        
        std::cout << "Enter opcode (0-7), or -1 to halt: ";
        int opcode {};

        if  (!(std::cin >> opcode) || opcode < -1 || opcode > 7)
        {
            std::cout << "Invalid opcode.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        cpu.state = CPUState::decode;

        if (opcode == -1) 
        {
            cpu.halted = true;
            continue;
        }

        instruction.operation = static_cast<ALUOperation>(opcode);

        if (instruction.operation == ALUOperation::INC || instruction.operation == ALUOperation::DEC)
        {
            executeInstruction(cpu, instruction);
        }
        else
        {
            std::cout << "Enter operand: ";
            int operand {};

            if  (!(std::cin >> operand))
            {
                std::cout << "Invalid opcode.\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            instruction.operand = static_cast<std::uint8_t>(operand);

            cpu.state = CPUState::execute;

            executeInstruction(cpu, instruction);
            
        }
        cpu.state = CPUState::idle;
        printInformation(cpu, instruction);



    }
    cpu.state = CPUState::halted;
    
    return 0;
}