#include "decoder.h"
#include "register.h"
#include <iostream>
#include <limits>

int main()
{
    int instructionsExecuted{0};

    std::cout << "CPU Simulator\n" 
              << "(Enter q to exit)\n\n";
    
    while (true)
    {
        std::cout << "Instruction: ";

        std::string input{};
        std::cin >> input;

        if (input == "q" || input == "quit")
            break;

        Instruction instruction{};

        try
        {
            instruction = static_cast<Instruction>(std::stoul(input, nullptr, 16));
        }
        catch (...)
        {
            std::cerr << "Invalid instruction.\n\n";
            continue;
        }

        auto opcode = getOpcode(instruction);
        auto destination = getDestination(instruction);
        auto immediate = getImmediate(instruction);

        if (executeInstruction(opcode, destination, immediate))
            ++instructionsExecuted;
        
    }
    printStatistics(instructionsExecuted);

    return 0;
}