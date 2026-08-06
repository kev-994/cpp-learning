#include "alu.h"
#include "interface.h"
#include <iostream>
#include <limits>

int main()
{
    std::uint16_t accumulator{};
    
    while (true)
    {
        printMenu();

        std::cout << "Enter an option: ";
        int input{};

        if (!(std::cin >> input || input < 1 || input > 11))
        {
            std::cout << "That is an invalid option.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (!executeInstruction(input, accumulator))
        {
            std::cout << "Exiting...\n";
            return 0;
        }


    }

    return 0;
}