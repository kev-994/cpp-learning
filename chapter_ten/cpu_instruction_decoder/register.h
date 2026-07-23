#pragma once
#include "decoder.h"

inline constexpr Opcode NOP{0};
inline constexpr Opcode LOAD{1};
inline constexpr Opcode ADD{2};
inline constexpr Opcode SUB{3};
inline constexpr Opcode PRINT{4};

inline RegisterValue R0{};
inline RegisterValue R1{};
inline RegisterValue R2{};
inline RegisterValue R3{};
inline RegisterValue R4{};
inline RegisterValue R5{};
inline RegisterValue R6{};
inline RegisterValue R7{};
inline RegisterValue R8{};
inline RegisterValue R9{};
inline RegisterValue R10{};
inline RegisterValue R11{};
inline RegisterValue R12{};
inline RegisterValue R13{};
inline RegisterValue R14{};
inline RegisterValue R15{};

Opcode getOperation(Opcode opcode);
bool executeInstruction(Opcode opcode, RegisterID destination, Immediate immediate);
void printStatistics(int instructionsExecuted);