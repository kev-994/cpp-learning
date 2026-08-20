#pragma once

#include <array>
#include <iostream>

struct Input
{
    bool a; // msb
    bool b;
    bool c; // lsb
};

std::array<Input, 8> generateTruthTableInputs();
void printTruthTable(const std::array<Input, 8>& truthTableInputs);