#include "Counter.h"
#include <iostream>

int main()
{
    Counter counterA{};
    std::cout << counterA.value() << '\n';
    counterA.tick();
    counterA.tick();
    std::cout << counterA.value() << '\n';

    Counter counterB{100};
    std::cout << counterB.value() << '\n';
    counterB.tick();
    std::cout << counterB.value() << '\n';

    return 0;
    
}