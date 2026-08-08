#include "register.h"
#include <iostream>
#include <cstdint>
#include <limits>

int main()
{
    std::uint32_t reg{};
    
    std::cout << "1. Set\n"
              << "2. Add\n"
              << "3. Reset\n"
              << "4. Print\n"
              << "5. Exit\n";
    
    while (true)
    {
        std::cout << "\n> ";
        int input{};
        std::cin >> input;

        switch (input)
        {
            case 1: 
            {
                std::cout << "Value: ";
                std::uint32_t value{};
                std::cin >> value;

                setRegister(reg, value);
                break;
            }
            case 2:
            {
                std::cout << "Value: ";
                std::uint32_t value{};
                std::cin >> value;

                addToRegister(reg, value);
                break;
            }
            case 3:
            {
                resetRegister(&reg);
                break;
            }
            case 4:
            {
                printRegister(reg);
                break;
            }
            case 5:
            {
                return 0;
            }
        }
    }    
           
    
    
    return 0;
}