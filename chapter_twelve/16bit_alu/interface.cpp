#include "interface.h"
#include "alu.h"
#include <iostream>
#include <string>
#include <format>
#include <limits>

void printMenu()
{
    std::cout << std::string(7, '=') << " 16-bit ALU Control Unit Simulator " 
              << std::string(7, '=') << '\n';

    std::cout << "1. Load value\n"
              << "2. ADD\n"
              << "3. SUB\n"
              << "4. AND\n"
              << "5. OR\n"
              << "6. XOR\n"
              << "7. Shift left\n"
              << "8. Shift right\n"
              << "9. Print register\n"
              << "10. Reset\n"
              << "11. Exit\n\n";
        
}

void printBinary(std::uint16_t value)
{
    std::cout << std::format("{:016b}\n", value);
}

namespace
{
    std::uint16_t getValidNum()
    {
        std::cout << "Enter a value: ";
        std::uint16_t value{};
        
        while (true)
        {
            if (!(std::cin >> value))
            {
                std::cout << "That is an invalid option,  please try again: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
bool executeInstruction(int input, std::uint16_t& reg)
{
    switch (input)
    {
        case LOAD:
        {
            loadRegister(reg, getValidNum());
            return true;
        }
        case ADD:
        {
            add(reg, getValidNum());
            return true;
        }
        case SUB:
        {
            sub(reg, getValidNum());
            return true;
        }
        case AND:
        {
            bitwiseAnd(reg, getValidNum());
            return true;
        }
        case OR:
        {
            bitwiseOr(reg, getValidNum());
            return true;
        }
        case XOR:
        {
            bitwiseXor(reg, getValidNum());
            return true;
        }
        case SHIFT_LEFT:
        {
            shiftLeft(reg, getValidNum());
            return true;
        }
        case SHIFT_RIGHT:
        {
            shiftRight(reg, getValidNum());
            return true;
        }
        case PRINT_REGISTER:
        {
            printRegister(reg);
            return true;
        }
        case RESET:
        {
            resetRegister(reg);
            return true;
        }
        case EXIT:
            return false;
        default:
            return false;
    }
}