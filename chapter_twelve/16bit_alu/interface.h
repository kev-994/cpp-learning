#pragma once
#include <cstdint>

void printMenu();
void printBinary(std::uint16_t value);
bool executeInstruction(int input, std::uint16_t& reg);
