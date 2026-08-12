#include "Register.h"
#include "RegisterBank.h"
#include <iostream>
#include <format>
#include <string>
#include <limits>

int main()
{
    RegisterBank bank{};

    std::cout << std::string(3, '=') << ' ' << "REGISTER BANK" << ' ' << std::string(3, '=') << "\n\n";
    std::cout << "1. Read register\n"
              << "2. Write register\n"
              << "3. Display registers\n"
              << "4. Exit\n\n";

    while (true)
    {
        std::cout << "> ";
        int input{};

        if (!(std::cin >> std::dec >> input) || input < 1 || input > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << '\n';

        switch (input)
        {
        case 1: 
        {
            std::cout << "Address: ";
            std::uint32_t address {};
            std::cin >> std::hex >> address;
            auto result{bank.read(address)};
            if (result)            
                std::cout << std::format("0x{:02X}", address) << ": " << std::format("0x{:08X}", *result) << "\n\n";
            else
                std::cout << "Address is non-readable or invalid.\n\n";
            break;
        }
        case 2: 
        {    
            std::cout << "Address: ";
            std::uint32_t address {};
            std::cin >> std::hex >> address;
            std::cout << "Value: ";
            std::uint32_t value {};
            std::cin >> std::hex >> value;
            auto result {bank.write(address, value)};
            switch (result)
            {
            case WriteResult::Success: 
                std::cout << "Write was successful.\n\n";
                break;
            case WriteResult::InvalidAddress: 
                std::cout << "Invalid address entered.\n\n";
                break;
            case WriteResult::ReadOnly:
                std::cout << "Register is read-only.\n\n";
                break;
            }
            break;
        }
        case 3: 
        {
            bank.displayRegisters();
            break;
        }
        case 4: 
        {
            std::cout << "Exiting...\n";
            return 0;
        }
        }
        
    }

    return 0;
}