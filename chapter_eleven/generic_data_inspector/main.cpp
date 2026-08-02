#include "utility.h"
#include "templates.h"
#include <iostream>
#include <limits>

int main()
{
    
    while (true)
    {
        std::cout << "1. Integer\n"
                  << "2. Double\n"
                  << "3. Character\n"
                  << "4. Exit\n\n";            
    
        int input{};
        if (!(std::cin >> input) || input < 1 || input > 4)
        {
            std::cout << "That input is invalid, try again.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (input)
        {
        case 1:
        {    
            std::cout << "Enter an integer: ";
            int integer{};
            std::cin >> integer;
            printValue(integer);
            std::cout << "Absolute value: " << absoluteValue(integer) << "\n\n";
            break;
        }    
        case 2:
        {    
            std::cout << "Enter a double: ";
            double num{};
            std::cin >> num;
            printValue(num);
            std::cout << "Absolute value: " << absoluteValue(num) << "\n\n";
            break;
        }
        case 3:
        {    
            std::cout << "Enter a character: ";
            char character{};
            std::cin >> character;
            std::cout << "\nCharacter: " << character << '\n';
            std::cout << "ASCII value: ";
            printASCIIValue(character);
            std::cout << "\n\n";
            break;
        }
        case 4:
            return 0;
        }

    }


    return 0;
}

// should ideally validate all inputs rather than just the menu input 