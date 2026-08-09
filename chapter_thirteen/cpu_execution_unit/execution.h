#pragma once
#include <cstdint>

enum class ALUOperation
{
    LOAD,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    INC,
    DEC,
};

struct Instruction
{
    ALUOperation operation {};
    std::uint8_t operand {};
};

struct CPU
{
    std::uint8_t accumulator {0};
    bool zeroFlag {};
    bool halted{};
};

void modifyZeroFlag(CPU& cpu);