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

enum class CPUState
{
    idle,
    decode,
    execute,
    halted,
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
    CPUState state{CPUState::idle};
};

void modifyZeroFlag(CPU& cpu);

void printInformation(const CPU* cpu, const Instruction& instruction);

void executeInstruction(CPU& cpuPtr, const Instruction& instruction);

