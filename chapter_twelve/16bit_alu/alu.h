#pragma once
#include <cstdint>

// Operations, results of operations are stored in the register by defualt
inline constexpr int LOAD          {1};
inline constexpr int ADD           {2};
inline constexpr int SUB           {3};
inline constexpr int AND           {4};
inline constexpr int OR            {5};
inline constexpr int XOR           {6};
inline constexpr int SHIFT_LEFT    {7};
inline constexpr int SHIFT_RIGHT   {8};
inline constexpr int PRINT_REGISTER{9};
inline constexpr int RESET         {10};
inline constexpr int EXIT          {11};


void loadRegister(std::uint16_t& reg, std::uint16_t value);
void resetRegister(std::uint16_t& reg);
void printRegister(const std::uint16_t& reg);
void add(std::uint16_t& reg, std::uint16_t value);
void sub(std::uint16_t& reg, std::uint16_t value);
void bitwiseAnd(std::uint16_t& reg, std::uint16_t value);
void bitwiseOr(std::uint16_t& reg, std::uint16_t value);
void bitwiseXor(std::uint16_t& reg, std::uint16_t value);
void shiftLeft(std::uint16_t& reg, unsigned int value);
void shiftRight(std::uint16_t& reg, unsigned int value);


