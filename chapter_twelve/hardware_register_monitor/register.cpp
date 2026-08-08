#include "register.h"
#include <cstdint>
#include <iostream>

void setRegister(std::uint32_t& reg, ::uint32_t value)
{
    reg = value;
    std::cout << '\n' << "Register: " << reg << '\n';
}

void addToRegister(std::uint32_t& reg, ::uint32_t value)
{
    reg += value;
    std::cout << '\n' << "Register: " << reg << '\n';
}


void resetRegister(std::uint32_t* reg)
{
    if (!reg)
        return;
    *reg = 0;    
    std::cout << '\n' << "Register: " << *reg << '\n';
}

void printRegister(const std::uint32_t reg)
{
    std::cout << "Register: " << reg << '\n';
}

