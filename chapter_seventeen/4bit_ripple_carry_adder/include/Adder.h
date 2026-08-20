# pragma once

#include "TruthTable.h"

struct FullAdderResult
{
    bool sum {};
    bool carryOut {};
};

struct AdderResult
{
    std::array<bool, 4> sum {};
    bool carryOut {};
};

void printFullAdder(const std::array<Input, 8>& truthTableInputs);

AdderResult add4(const std::array<bool, 4>& A, const std::array<bool, 4>& B);