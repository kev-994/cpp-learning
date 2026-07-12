/*
Bit 0: Carry flag
Bit 1: Zero flag
Bit 2: Negative flag
Bit 3: Overflow flag
Bit 4: Interrupt enabled flag
Bit 5: Supervisor mode flag
Bit 6: Reserved
Bit 7: Error flag

CPU Status Register Simulator

1. Set a flag
2. Clear a flag
3. Toggle a flag
4. Check a flag
5. Print register in decimal
6. Print register in binary
7. Exit
*/

#include <bitset>
#include <iostream>

// Given a relevant option, choose flag number and so get necessary bit
unsigned int mask()
{
    std::cout << "Choose flag number: ";
    unsigned int flagNumber{};
    std::cin >> flagNumber;

    if (flagNumber > 7)
    {
        std::cout << "Invalid flag number\n";
        return 0;
    }

    return 1u << flagNumber;
}



int main()
{
    std::cout << "CPU Status Register Simulator\n\n";
    std::cout << "1. Set a flag\n";
    std::cout << "2. Clear a flag\n";
    std::cout << "3. Toggle a flag\n";
    std::cout << "4. Check a flag\n";
    std::cout << "5. Print register in decimal\n";
    std::cout << "6. Print register in binary\n";
    std::cout << "7. Exit\n";

    unsigned int status{};

 
    bool running{true};

    while (running)
    {
        std::cout << "\nChoose option: ";
        unsigned int option{};
        std::cin >> option;

        if (option == 1)
        {
            status |= mask();
        }

        else if (option == 2)
        {
            status &= ~mask();
        }

        else if (option == 3)
        {
            status ^= mask();
        }

        else if (option == 4)
        {
            if (status & mask())
            {
                std::cout << "Flag is on\n";
            }
            else
            {
                std::cout << "Flag is off\n";
            }
        }

        else if (option == 5)
        {
            std::cout << "Decimal value: " << status << '\n';
        }

        else if (option == 6)
        {
            std::cout << "Binary value: " << std::bitset<8>{status} << '\n';
        }

        else if (option == 7)
        {
            std::cout << "Exiting... \n";
            running = false;
        }

        else
        {
            std::cout << "That is not a valid option, try again\n";
        }


    }
   return 0;
}