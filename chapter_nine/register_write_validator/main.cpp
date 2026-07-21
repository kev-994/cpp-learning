#include "register.h"
#include <iostream>

int main()
{
    
    while (true)
    {
        int registerValue{getRegisterValue()};
        
        if (registerValue == -1)
            break;

        updateStatistics(registerValue);    
        std::cout << "Register updated to " << registerValue << '\n';
    }
    printRegisterReport();

    return 0;
}