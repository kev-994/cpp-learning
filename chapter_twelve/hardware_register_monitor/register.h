# pragma once
#include <cstdint>

void setRegister(std::uint32_t& reg, ::uint32_t value);
void addToRegister(std::uint32_t& reg, ::uint32_t value);
void resetRegister(std::uint32_t* reg);
void printRegister(const std::uint32_t reg);