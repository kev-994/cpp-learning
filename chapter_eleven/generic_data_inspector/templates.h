#pragma once
#include <iostream>
#include <string>

template <typename T>
void printValue(T input)
{
    std::cout << "\nValue: " << input << '\n';
}

template <typename T>
T absoluteValue(T input)
{
    if (input < 0)
        return input * -1;
    return input;
}

bool absoluteValue(bool) = delete;

template <typename T, typename U>
bool areEqual(T x, U y)
{
    return x == y;
}

template <int N>
void printBox(std::string str)
{
    std::cout << std::string(N, '#') << '\n'
              << str << '\n'
              << std::string(N, '#') << "\n\n";
}