#include <iostream>
#include <cstdint>

void printEight(const std::uint32_t arr[])
{
    for (std::size_t i{}; i < 8; ++i)
    {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << '\n';
}

const std::uint32_t* largestValue(std::uint32_t arr[])
{
    std::uint32_t* largestValue {arr};
    
    for (std::size_t i{}; i < 8; ++i)
    {
        if (*(arr + i) > *largestValue) largestValue = (arr + i);
    }
    return largestValue;
}

int main()
{
    std::uint32_t buffer[8] {1, 2, 3, 4, 994, 6, 7, 8};
    printEight(buffer);
    std::cout << "The largest value in the array is " << *largestValue(buffer) << '\n';

    return 0;
}