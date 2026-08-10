#include "alu_implementation.h"

void loadRegister(CPU& cpu, const Instruction& instruction)
{
    cpu.accumulator = instruction.operand;
    modifyZeroFlag(cpu);
}

void addToRegister(CPU& cpu, const Instruction& instruction)
{
    cpu.accumulator = static_cast<std::uint8_t>(cpu.accumulator + instruction.operand);
    modifyZeroFlag(cpu);
}

void subFromRegister(CPU& cpu, const Instruction& instruction)
{
    cpu.accumulator = static_cast<std::uint8_t>(cpu.accumulator - instruction.operand);
    modifyZeroFlag(cpu);
}

void bitwiseAnd(CPU& cpu, const Instruction& instruction)
{
    cpu.accumulator = static_cast<std::uint8_t>(cpu.accumulator & instruction.operand);
    modifyZeroFlag(cpu);
}

void bitwiseOr(CPU& cpu, const Instruction& instruction)
{
    cpu.accumulator = static_cast<std::uint8_t>(cpu.accumulator | instruction.operand);
    modifyZeroFlag(cpu);
}

void bitwiseXor(CPU& cpu, const Instruction& instruction)
{
    cpu.accumulator = static_cast<std::uint8_t>(cpu.accumulator ^ instruction.operand);
    modifyZeroFlag(cpu);
}

void incrementRegister(CPU& cpu)
{
    ++cpu.accumulator;
    modifyZeroFlag(cpu);
}

void decrementRegister(CPU& cpu)
{
    --cpu.accumulator;
    modifyZeroFlag(cpu);
}


