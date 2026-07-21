#include "register.h"
#include <iostream>
#include <limits>
#include <cassert>

namespace
{
    constexpr int minRegisterValue{0};
    constexpr int maxRegisterValue{255};
    
    int successfulWrites{0};
    int minValueWritten{maxRegisterValue};
    int maxValueWritten{minRegisterValue};

}

int getRegisterValue()
{
    while (true) // loop until user enters a valid input
    { 
        std::cout << "Enter register value (0-255, -1 to quit): ";
        int registerValue{};
        std::cin >> registerValue;

        bool success{std::cin}; // could instead use if (!(std::cin >> registerValue)) in my if statement
        std::cin.clear(); // put us back in 'normal' operation mode (if needed)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove any extra input

        if (!success || registerValue < -1 || registerValue > maxRegisterValue)
        {
            std::cerr << "Invalid register value.\n";
            continue;
        }

        return registerValue;
    } 
}

void updateStatistics(int registerValue)
{
    assert(registerValue >= minRegisterValue);
    assert(registerValue <= maxRegisterValue);
    
    if (registerValue < minValueWritten)  minValueWritten = registerValue;
    if (registerValue > maxValueWritten) maxValueWritten = registerValue;
    ++successfulWrites;
}

void printRegisterReport()
{
    std::cout << "----- Register Report -----\n\n";
    std::cout << "Successful writes: " << successfulWrites << '\n';
    if (successfulWrites != 0)
    {
        std::cout << "Minimum value written: " << minValueWritten << '\n';
        std::cout << "Maximum value written: " << maxValueWritten << '\n';
    }

}
