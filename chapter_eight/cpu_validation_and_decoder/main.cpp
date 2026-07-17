#include "instruction.h"
#include <iostream>

int main()
{
    std::cout << "Enter a 32-bit instruction: ";
    std::cin >> std::hex >>  cpu::instruction;

    cpu::printDecodedInstruction();

    return 0;
}