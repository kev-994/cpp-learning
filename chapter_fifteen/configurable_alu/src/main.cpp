#include "../include/ALU.h"
#include <cstdint>
#include <iostream>

int main()
{
    using ALU32 = ALU<std::uint32_t>;
    using ALU16 = ALU<std::uint16_t>;

    // --------------------------------------------------
    // 1. Create two 32-bit ALUs
    // --------------------------------------------------

    ALU32 alu1 {};
    ALU32 alu2 {};

    std::cout << "Initial ALU state:\n";
    printALU(alu1);

    // --------------------------------------------------
    // 2. Test member-function chaining and ADD
    // --------------------------------------------------

    alu1.setA(10)
        .setB(5)
        .setOperation(ALU32::Operation::ADD);

    std::cout << "\nAfter ADD:\n";
    printALU(alu1);

    // --------------------------------------------------
    // 3. Test SUBTRACT and zero flag
    // --------------------------------------------------

    alu1.setA(10)
        .setB(10)
        .setOperation(ALU32::Operation::SUB);

    std::cout << "\nAfter SUBTRACT:\n";
    printALU(alu1);

    // --------------------------------------------------
    // 4. Test bitwise operations
    // --------------------------------------------------

    alu1.setA(0b1100)
        .setB(0b1010)
        .setOperation(ALU32::Operation::AND);

    std::cout << "\nAfter AND:\n";
    printALU(alu1);

    alu1.setOperation(ALU32::Operation::OR);

    std::cout << "\nAfter OR:\n";
    printALU(alu1);

    alu1.setOperation(ALU32::Operation::XOR);

    std::cout << "\nAfter XOR:\n";
    printALU(alu1);

    // --------------------------------------------------
    // 5. Test shifts
    // --------------------------------------------------

    alu1.setA(1)
        .setB(4)
        .setOperation(ALU32::Operation::SHIFT_LEFT);

    std::cout << "\nAfter SHIFT LEFT:\n";
    printALU(alu1);

    alu1.setOperation(ALU32::Operation::SHIFT_RIGHT);

    std::cout << "\nAfter SHIFT RIGHT:\n";
    printALU(alu1);

    // --------------------------------------------------
    // 6. Demonstrate that alu1 and alu2 share the
    //    same static operation counter
    // --------------------------------------------------

    alu2.setA(20)
        .setB(10)
        .setOperation(ALU32::Operation::ADD);

    std::cout << "\n32-bit ALU operation count: "
              << ALU32::getOperationCount() << '\n';

    // --------------------------------------------------
    // 7. Demonstrate that a different template
    //    specialization has its own static counter
    // --------------------------------------------------

    ALU16 alu16 {};

    alu16.setA(5)
         .setB(3)
         .setOperation(ALU16::Operation::ADD);

    std::cout << "16-bit ALU operation count: "
              << ALU16::getOperationCount() << '\n';

    std::cout << "32-bit ALU operation count: "
              << ALU32::getOperationCount() << '\n';

    return 0;
}