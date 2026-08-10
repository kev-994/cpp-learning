#include <iostream>
#include <cstdint>

template <typename T>
struct Register
{
    T value{};
    
    void print()
    {
        std::cout << static_cast<int>(value) << '\n';
    }
    
    void change(T newValue)
    {
        value = newValue;
    }
};

using Register32 = Register<std::uint32_t>; 

/*
template <typename T>
using RegisterType = Register<T>;
*/

int main()
{
    Register<std::uint8_t> reg8{100};
    reg8.print();
    reg8.change(5);
    reg8.print();

    Register32 reg32{5738};
    reg32.print();
    reg32.change(994);
    reg32.print();

    return 0;
}

