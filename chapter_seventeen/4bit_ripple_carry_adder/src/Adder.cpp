#include "Adder.h"
#include "LogicGates.h"
#include "TruthTable.h"
#include <array>
#include <string>

FullAdderResult fullAdder(bool A, bool B, bool carryIn)
{
    FullAdderResult fadderResult {};
    fadderResult.sum = xorGate(xorGate(A, B), carryIn); //  Sum = A XOR B XOR Cin
    fadderResult.carryOut = orGate(andGate(A, B), andGate(carryIn, xorGate(A, B))); // Cout = (A AND B) OR (Cin AND (A XOR B))
    return fadderResult; 
}

void printFullAdder(const std::array<Input, 8>& truthTableInputs)
{
    std::cout << "A B C | Sum Cout\n"
              << std::string(18, '-') << '\n';
    for (const auto& inputs : truthTableInputs)
    {
        FullAdderResult fadderResult  {fullAdder(inputs.a, inputs.b, inputs.c)};
        std::cout << inputs.a << ' '<< inputs.b << ' ' << inputs.c << " |  " << fadderResult.sum << "  " << fadderResult.carryOut << '\n'; 
    }
}

AdderResult add4(const std::array<bool, 4>& A, const std::array<bool, 4>& B)
{
    AdderResult adderResult {};
    bool carryOut {};
    for (std::size_t i{}; i < A.size(); ++i)
    {
        auto result {fullAdder(A[i], B[i], carryOut)};
        adderResult.sum[i] = result.sum;
        carryOut = result.carryOut;
           
    }
    adderResult.carryOut = carryOut;
    return adderResult;
}