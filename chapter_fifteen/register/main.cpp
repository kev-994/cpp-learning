#include "Register.h"
#include <iostream>

int main()
{
    Register r{19, Register::Access::ReadOnly};
    Register rw{1, Register::Access::ReadWrite};

    std::cout << "Read only: " << r.read() << '\n';
    std::cout << "Read/Write: " << rw.read() << '\n';
    r.write(10);
    rw.write(994);
    std::cout << "Read only: " << r.read() << '\n';
    std::cout << "Read/Write: " << rw.read() << '\n';
    rw.reset().write(101);
    std::cout << "Read/Write: " << rw.read() << '\n';

    return 0;

}