#include "utility.h"
#include <iostream>
#include <string>


void printASCIIValue(char input)
{
    std::cout << static_cast<int>(input) << '\n';
}



void printDivider(char character, int length)
{
    std::cout << std::string(length, character) << '\n';
}