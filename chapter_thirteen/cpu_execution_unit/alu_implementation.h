#pragma once
#include "execution.h"

void loadRegister(CPU& cpu, Instruction& instruction);
void addToRegister(CPU& cpu, Instruction& instruction);
void subFromRegister(CPU& cpu, Instruction& instruction);
void bitwiseAnd(CPU& cpu, Instruction& instruction);
void bitwiseOr(CPU& cpu, Instruction& instruction);
void bitwiseXor(CPU& cpu, Instruction& instruction);
void incrementRegister(CPU& cpu);
void decrementRegister(CPU& cpu);




