#pragma once

#include <cstdint>


using Instruction = uint32_t;
using Opcode = uint8_t;
using RegisterID = uint8_t;
using Immediate = uint32_t;
using RegisterValue = uint32_t;


Opcode getOpcode(Instruction instruction);

RegisterID getDestination(Instruction instruction);

Immediate getImmediate(Instruction instruction);