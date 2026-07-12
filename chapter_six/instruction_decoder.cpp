// 16-bit instruction decoder


#include <iostream>

bool validInstruction(unsigned int instruction)
{
    return instruction <= 0xFFFF;
}

int main()
{
    std::cout << "Enter a 16-bit instruction as an integer: ";
    unsigned int instruction{};
    std::cin >> instruction;

    if (!validInstruction(instruction))
    {
        std::cout << "Invalid instruction\n";
        return 1;
    }

    unsigned int imm{instruction & 0xF};
    unsigned int source{(instruction >> 4) & 0xF};
    unsigned int dest{(instruction >> 8) & 0xF};
    unsigned int opcode{(instruction >> 12) & 0xF};

    std::cout << "\nOpcode: " << opcode << '\n';
    std::cout << "Destination register: " << dest << '\n';
    std::cout << "Source register: " << source << '\n';
    std::cout << "Immediate value: " << imm << '\n';
    

    return 0;
}