#include "alu.h"
#include <iostream>
#include <format>



void loadRegister(std::uint16_t& reg, std::uint16_t value)
{
    reg = value;
}

void resetRegister(std::uint16_t& reg)
{
    reg = 0;
}

void printRegister(const std::uint16_t& reg)
{
    std::cout << "Decimal : " << reg << '\n'
              << "Hex     : " << std::format("0x{:04X}", reg) << '\n'
              << "Binary  : " << std::format("{:016b}", reg) << "\n\n"
              << "Upper byte : " << ((reg >> 8) & 0xFF) << '\n'
              << "Lower byte : " << (reg & 0xFF) << "\n\n"
              << "Even : " << ((reg % 2) ? "No" : "Yes") << '\n';
 
}

void add(std::uint16_t& reg, std::uint16_t value)
{
    reg += value;
}

void sub(std::uint16_t& reg, std::uint16_t value)
{
    reg -= value;
}

void bitwiseAnd(std::uint16_t& reg, std::uint16_t value)
{
    reg &= value;
}

void bitwiseOr(std::uint16_t& reg, std::uint16_t value)
{
    reg |= value;
}

void bitwiseXor(std::uint16_t& reg, std::uint16_t value)
{
    reg ^= value;
}

void shiftLeft(std::uint16_t& reg, unsigned int value)
{
    reg <<= value;
}

void shiftRight(std::uint16_t& reg, unsigned int value)
{
    reg >>= value;
}

