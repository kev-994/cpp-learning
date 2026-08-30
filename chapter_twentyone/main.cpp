#include "Register.h"

#include <cstdint>
#include <iostream>

int main()
{
    Register a{0x0F0F};
    Register b{0x00FF};

    // Arithmetic
    std::cout << "a + b = " << (a + b) << '\n';
    std::cout << "a - b = " << (a - b) << '\n';

    // Bitwise
    std::cout << "a & b = " << (a & b) << '\n';
    std::cout << "a | b = " << (a | b) << '\n';
    std::cout << "a ^ b = " << (a ^ b) << '\n';
    std::cout << "~b = " << (~b) << '\n';

    // Comparison
    std::cout << "a == b: " << (a == b) << '\n';
    std::cout << "a != b: " << (a != b) << '\n';

    // Increment / decrement
    Register c{0x0000FFFF};

    std::cout << "++c = " << ++c << '\n';
    std::cout << "c++ = " << c++ << '\n';
    std::cout << "after c++ = " << c << '\n';

    std::cout << "--c = " << --c << '\n';
    std::cout << "c-- = " << c-- << '\n';
    std::cout << "after c-- = " << c << '\n';

    // Overflow
    Register d{0xFFFFFFFF};

    std::cout << "overflow = " << (d + Register{1}) << '\n';

    Register e{0x00000000};

    std::cout << "underflow = " << (e - Register{1}) << '\n';

    // Subscript
    Register f{0b10101010};

    std::cout << "f[0] = " << f[0] << '\n';
    std::cout << "f[1] = " << f[1] << '\n';
    std::cout << "f[2] = " << f[2] << '\n';
    std::cout << "f[3] = " << f[3] << '\n';
    std::cout << "f[7] = " << f[7] << '\n';
    
    // Conversion
    uint32_t value = a;
    std::cout << "converted a = 0x"
              << std::hex << value << '\n';

    // Assignment
    Register g{0};
    g = 0xDEADBEEF;

    std::cout << "assigned g = " << g << '\n'; 

    return 0;
}







