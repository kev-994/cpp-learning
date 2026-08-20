#include <algorithm> // for std::sort
#include <array>
#include <chrono> // for std::chrono functions
#include <cstddef> // for std::size_t
#include <iostream>
#include <numeric> // for std::iota

const int g_arrayElements { 10000 };

class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:

    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

void sortArray(std::array<int, g_arrayElements>& array)
{
    for (auto start{array.begin()}; start != array.end()-1; ++start)
    {
        auto smallest {start};

        for (auto current {start + 1}; current < array.end(); ++current)
        {
            if (*current < *smallest)
                smallest = current;
        }

        std::swap(*start, *smallest);
    }    
}

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1
    std::array<int, g_arrayElements> array1{array};
    
    Timer t;

    std::ranges::sort(array); // Since C++20
    // If your compiler isn't C++20-capable
    // std::sort(array.begin(), array.end());

    std::cout << "Time taken for std::sort: " << t.elapsed() << " seconds\n";
    
    
    t.reset();
    sortArray(array1);
    std::cout << "Time taken for implemented selection sort: " << t.elapsed() << " seconds\n";

    std::cout << "Results match: " << (array == array1 ? "yes\n" : "no\n");

    return 0;
}