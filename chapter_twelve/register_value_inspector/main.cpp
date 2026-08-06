#include "register.h"
#include <iostream>
#include <limits>


int main()
{
                                            
    while (true)
    {
        printMenu();
        
        int input{};
        if(!(std::cin >> input) || input < 1 || input > 6)
        {
            std::cout << "That input is invalid, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (input)
        {
        case 1:
        {
            readRegisterValue();
            break;
        }
        case 2:
        {
            printRegisterInfo();
            break;
        }
        case 3:
        {
            toggleDebugMode();
            break;
        }
        case 4:
        {
            compareRegisters();
            break;
        }
        case 5:
        {
            resetRegister();
            break;
        }
        case 6:
        {
            std::cout << "Exiting...\n";
            return 0;
        }    
    }
    }
               
    
    return 0;
}