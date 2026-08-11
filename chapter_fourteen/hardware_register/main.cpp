#include "Register.h"
#include <iostream>
#include <format>


int main()
{
    Register reg16{};
    std::cout << std::format("0x{:04X}\n", reg16.read());
    reg16.write(0x1234);
    std::cout << std::format("0x{:04X}\n", reg16.read());
}