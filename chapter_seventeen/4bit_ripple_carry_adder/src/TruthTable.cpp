#include "TruthTable.h"
#include "LogicGates.h"
#include <array>
#include <iostream>

std::array<Input, 8> generateTruthTableInputs()
{
    std::array<Input, 8> truthTableInputs {};

    for (std::size_t i{}; i < truthTableInputs.size(); ++i)
    {
        truthTableInputs[i].c = i & 1;
        truthTableInputs[i].b = (i >> 1) & 1;
        truthTableInputs[i].a = (i >> 2) & 1;
    }

    return truthTableInputs;
}

bool calculateOutput(const Input& inputs)
{
    bool res1 {andGate(inputs.a, inputs.b)};
    bool res2 {xorGate(inputs.b, inputs.c)};
    return orGate(res1, res2);
}

void printTruthTable(const std::array<Input, 8>& truthTableInputs)
{
    std::cout << "A B C | OUT\n"
              << "-----------\n";
    for (const auto& inputs : truthTableInputs)
    {
        std::cout << inputs.a << ' '<< inputs.b << ' ' << inputs.c << " |  " << calculateOutput(inputs) << '\n'; 
    }
}