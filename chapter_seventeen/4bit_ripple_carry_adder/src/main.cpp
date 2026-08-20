#include "TruthTable.h"
#include "Adder.h"
#include <iostream>

int main()
{
    auto test {add4({1, 1, 1, 1}, {1, 1, 1, 1})};  // index 0 is lsb, index 3 is msb

    std::cout << "Sum: ";
    for (const auto& bit : test.sum)
    {
        std::cout << bit;
    }
    std::cout << "\nCarry out: " << test.carryOut << '\n';

    return 0;

}