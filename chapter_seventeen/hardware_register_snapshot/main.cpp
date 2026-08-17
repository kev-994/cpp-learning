#include <cstdint>
#include <array>
#include <iostream>

struct RegisterSnapshot
{
    std::uint32_t m_R1 {};
    std::uint32_t m_R2 {};
    std::uint32_t m_R3 {};
    std::uint32_t m_R4 {};

};

std::uint32_t sumOfValues(const std::array<std::uint32_t, 4>& arr)
{
    std::uint32_t sum {};
    for (const auto& val : arr) sum += val;
    return sum;
}

std::size_t indexOfLargest(const std::array<std::uint32_t, 4>& arr)
{
    std::uint32_t largest {};
    std::size_t indexOfLargest {};
    for (std::size_t i{}; i < arr.size(); ++i)
    {
        if (arr[i] > largest) 
        {
            largest = arr[i];
            indexOfLargest = i;
        }
    }
    return indexOfLargest;
    
}

int main()
{
    RegisterSnapshot regSnap {1, 994, 3, 4};
    std::array<std::uint32_t, 4> store {regSnap.m_R1, regSnap.m_R2, regSnap.m_R3, regSnap.m_R4};

    for (const auto& val : store)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    std::cout << "The sum of all values is " << sumOfValues(store) << '\n';
    std::cout << "The index of the largest register value is " << indexOfLargest(store) << '\n';
    
}