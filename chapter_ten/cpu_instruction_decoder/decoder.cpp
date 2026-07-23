#include "decoder.h"
#include <iostream>

Opcode getOpcode(Instruction instruction)
{
    return ((instruction >> 28) & 0xF);
}


RegisterID getDestination(Instruction instruction)
{
    return ((instruction >> 24) & 0xF);
}

Immediate getImmediate(Instruction instruction)
{
    return instruction & 0xFFFFFF;
}
