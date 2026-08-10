#pragma once
#include "execution.h"

void loadRegister(CPU& cpu, const Instruction& instruction);
void addToRegister(CPU& cpu, const Instruction& instruction);
void subFromRegister(CPU& cpu, const Instruction& instruction);
void bitwiseAnd(CPU& cpu, const Instruction& instruction);
void bitwiseOr(CPU& cpu, const Instruction& instruction);
void bitwiseXor(CPU& cpu, const Instruction& instruction);
void incrementRegister(CPU& cpu);
void decrementRegister(CPU& cpu);




