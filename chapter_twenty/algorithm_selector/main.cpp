#include <iostream>
#include <array>
#include <sstream>

template <typename T, std::size_t N>
auto sum(const std::array<T, N>& arr)
{
    int sum {};
    for (const auto& val : arr)
    {
        sum += val;
    }
    return sum;
}

template <typename T, std::size_t N>
auto largest(const std::array<T, N>& arr)
{
    int largest {arr[0]};
    for (const auto& val : arr)
    {
        if (val > largest) largest = val;
    }
    return largest;
}

template <typename T, std::size_t N>
auto recursiveSum(const std::array<T, N>& arr, std::size_t startingIndex) // this function assumes array isnt empty
{
    if (startingIndex == N-1)
        return arr[N-1]; 
    return arr[startingIndex] + recursiveSum(arr, startingIndex + 1);
}

bool greaterThan50(int val)
{
    return val > 50;
}

template <typename T, std::size_t N>
int countIf(const std::array<T, N>& arr, auto condition) // auto allows countIf to accept arbitrary callable objects, including capturing lambdas.
{
    int count {};
    for (const auto& val : arr)
    {
        if (condition(val)) ++count;
    }
    return count;
}

int main(int argc, char* argv[])
{
    std::array arr {12, 75, 34, 91, 6, 48, 63};
    
    std::cout << "Sum: " << sum(arr) << '\n';
    std::cout << "Recursive sum: " << recursiveSum(arr, 0) << '\n';
    std::cout << "Largest: " << largest(arr) << '\n';
    std::cout << "Elements > 50: " << countIf(arr, greaterThan50) << '\n';

    std::stringstream convert{argv[1]}; // should really check argc is greater than 1 before hand
    int threshold {};
    if (convert >> threshold)
        std::cout << "Elements > " << threshold << " (uses lambda and command line argument): " << countIf(arr, [threshold](int val) {return val > threshold;}) << '\n';
    else
        std::cout << "Couldn't convert command line argument to int." << '\n';

    
    return 0;
}