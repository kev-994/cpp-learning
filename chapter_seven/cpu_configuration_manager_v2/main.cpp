#include "config.h"
#include <iostream>

int main()
{
    bool running{true};

    while (running)
    {
        std::cout << "\n1. View configuration\n";
        std::cout << "2. Set clock frequency\n";
        std::cout << "3. Toggle debug mode\n";
        std::cout << "4. Reset to defaults\n";
        std::cout << "5. Exit\n";

        std::cout << "Choose option: ";
        int option{};
        std::cin >> option;

        if (option == 1)
        {
            cpu::printConfig();
        }
        else if (option == 2)
        {
            cpu::setClockFrequency();
        }
        else if (option == 3)
        {
            cpu::toggleDebugMode();
        }
        else if (option == 4)
        {
            cpu::resetConfig();
        }
        else if (option == 5)
        {
            std::cout << "Exiting...\n";
            running = false;
        }
        else
        {
            std::cout << "That is not a valid option, try again\n";
        }
    }

    return 0;
}