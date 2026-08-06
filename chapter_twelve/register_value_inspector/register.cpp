#include "register.h"
#include <cstdint>
#include <iostream>
#include <limits>
#include <format>

namespace
{
    std::uint16_t registerValue{};
    std::uint16_t prevRegisterValue{};


    bool debugMode{false};
}


void printMenu()
{
    std::cout << std::string(10, '=') << " Register Inspector " << std::string(10, '=') 
              << "\n";
        
    std::cout << "1. Enter new register value\n"
              << "2. Display register information\n"
              << "3. Toggle a debug flag\n"
              << "4. Compare current value with previous value\n"
              << "5. Reset register\n"
              << "6. Exit\n\n";
}

void readRegisterValue()
{
    prevRegisterValue = registerValue;
    
    while (true)
    {
        std::cout << "Enter register value: ";
        if (!(std::cin >> registerValue))
            {
                std::cout << "That input is invalid, try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                continue;
            }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Register value updated.\n\n";
        break;    
    }
}

void printRegisterInfo()
{
    const auto& current {registerValue};
    std::cout << "Register value : " << current << "\n\n"
              << "Decimal : " << current << '\n'
              << "Hex     : " << std::format("0x{:04X}", current) << '\n'
              << "Binary  : " << std::format("{:016b}\n", current) << "\n\n"
              << "Even    : " << ((current % 2) ? "No\n" : "Yes\n")
              << "Zero    : " << ((current == 0) ? "Yes\n\n" : "No\n\n")
              << "Upper byte : " << ((current >> 8) & 0xFF) << '\n'
              << "Lower byte : " << (current & 0xFF) << "\n\n";

}

void toggleDebugMode()
{
    debugMode = !debugMode;
    std::cout << "Debug mode " << ((debugMode) ? "enabled\n\n" : "disabled\n\n"); 

}

void compareRegisters()
{
    const auto& current {registerValue};
    const auto& prev    {prevRegisterValue};
    if (current > prev)      std::cout << "Current value is greater than previous value\n\n";
    else if (current < prev) std::cout << "Current value is smaller than previous value\n\n";
    else                     std::cout << "No change in value\n\n";


}

void resetRegister()
{
    auto& current {registerValue};
    auto& prev    {prevRegisterValue};
    prev = current;
    current = 0;
    debugMode = false;
    std::cout << "Register has been reset.\n\n";
}
