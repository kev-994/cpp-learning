#include "Adder.h"

#include <array>
#include <cassert>
#include <iostream>

void testFullAdder()
{
    struct TestCase
    {
        std::array<bool, 4> A;
        std::array<bool, 4> B;
        std::array<bool, 4> expectedSum;
        bool expectedCarry;
    };

    const std::array<TestCase, 5> testCases
    {
        TestCase{
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            false
        },

        TestCase{
            {1, 0, 0, 0}, // 1
            {0, 1, 0, 0}, // 2
            {1, 1, 0, 0}, // 3
            false
        },

        TestCase{
            {1, 0, 1, 0}, // 5
            {1, 1, 0, 0}, // 3
            {0, 0, 0, 1}, // 8
            false
        },

        TestCase{
            {1, 1, 1, 1}, // 15
            {1, 0, 0, 0}, // 1
            {0, 0, 0, 0}, // 0
            true
        },

        TestCase{
            {1, 1, 1, 1}, // 15
            {1, 1, 1, 1}, // 15
            {0, 1, 1, 1}, // 14
            true
        }
    };

    for (const auto& test : testCases)
    {
        const auto result {add4(test.A, test.B)};

        assert(result.sum == test.expectedSum);
        assert(result.carryOut == test.expectedCarry);
    }

    std::cout << "All full-adder tests passed.\n";
}

int main()
{
    testFullAdder();
}