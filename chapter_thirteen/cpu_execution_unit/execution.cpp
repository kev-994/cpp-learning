#include "execution.h"
#include "alu_implementation.h"
#include <cstdint>
#include <iostream>
#include <string_view>

void modifyZeroFlag(CPU& cpu) // modifies when needed
{
    cpu.zeroFlag = (cpu.accumulator == 0);
}

void executeInstruction(CPU& cpu, const Instruction& instruction)
{
    switch (instruction.operation)
    {
    case ALUOperation::LOAD: 
    {
        loadRegister(cpu, instruction);
        break;
    }
    case ALUOperation::ADD: 
    {
        addToRegister(cpu, instruction);
        break;
    }
    case ALUOperation::SUB:
    {
        subFromRegister(cpu, instruction);
        break;
    }
    case ALUOperation::AND:
    {
        bitwiseAnd(cpu, instruction);
        break;
    }
    case ALUOperation::OR:
    {
        bitwiseOr(cpu, instruction);
        break;
    }
    case ALUOperation::XOR:
    {
        bitwiseXor(cpu, instruction);
        break;
    }
    case ALUOperation::INC:
    {
        incrementRegister(cpu);
        break;
    }
    case ALUOperation::DEC:
    {
        decrementRegister(cpu);
        break;
    }
    default: std::cout << "Invalid operation entered.\n";
    }
}

constexpr std::string_view getOpName(ALUOperation operation) // enums are tiny and cheap to copy, pass by value
{
    using enum ALUOperation;
    switch (operation)
    {
    case LOAD: return "LOAD";
    case ADD:  return "ADD";
    case SUB:  return "SUB";
    case AND:  return "AND";
    case OR:   return "OR";
    case XOR:  return "XOR";
    case INC:  return "INC";
    case DEC:  return "DEC";
    default: return "???";
    }
}

std::ostream& operator<<(std::ostream& out, ALUOperation operation) // so the operation names can be printed
{
    return out << getOpName(operation);
}

void printInformation(const CPU& cpu, const Instruction& instruction)
{
    std::cout << '\n';
    if ((instruction.operation != ALUOperation::INC) && (instruction.operation != ALUOperation::DEC))
        std::cout << instruction.operation << " " << static_cast<int>(instruction.operand) << '\n';
    else
        std::cout << instruction.operation << '\n';
              
    std::cout << "ACC: " << static_cast<int>(cpu.accumulator) << '\n'
              << "Z: " << cpu.zeroFlag << "\n\n";
}

