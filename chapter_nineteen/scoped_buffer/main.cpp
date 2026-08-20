#include <cstddef>
#include <utility>
#include <iostream>

class ScopedBuffer
{
public:
    ScopedBuffer(std::size_t size)
        : m_arr {new int[size]{}}
        {}
    
    ~ScopedBuffer()
    {
        delete[] m_arr;
    }

    ScopedBuffer(ScopedBuffer&& other) noexcept// move constructor
    : m_arr {other.m_arr}
    {
        other.m_arr = nullptr;
    }
    ScopedBuffer& operator=(ScopedBuffer&& other) noexcept // move assignment
    {
        if (this == &other)
            return *this;
        delete[] m_arr;
        m_arr = other.m_arr;
        other.m_arr = nullptr;
        return *this;          
    }

    ScopedBuffer(const ScopedBuffer&) = delete; // disallow copy construction
    ScopedBuffer& operator=(const ScopedBuffer&) = delete; // disallow copy assignment

    int& operator[](std::size_t index)
    {
        return *(m_arr + index); // equivalent to m_arr[index]
    }
private:
    int* m_arr {};
};

int main()
{
    ScopedBuffer a{2};
    a[0] = 1;
    a[1] = 2;
    ScopedBuffer b {std::move(a)};
    std::cout << b[0] << b[1] << '\n';

    return 0;
}