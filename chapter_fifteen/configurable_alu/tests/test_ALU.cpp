#include "../include/ALU.h"

#include <cassert>
#include <cstdint>
#include <iostream>

using ALU32 = ALU<std::uint32_t>;
using ALU16 = ALU<std::uint16_t>;

void testDefaultState()
{
    ALU32 alu {};

    assert(alu.getResult() == 0);
    assert(alu.getZeroFlag() == false);
}

void testAddition()
{
    ALU32 alu {};

    alu.setA(10)
       .setB(5)
       .setOperation(ALU32::Operation::ADD);

    assert(alu.getResult() == 15);
    assert(alu.getZeroFlag() == false);
}

void testSubtraction()
{
    ALU32 alu {};

    alu.setA(10)
       .setB(5)
       .setOperation(ALU32::Operation::SUB);

    assert(alu.getResult() == 5);
    assert(alu.getZeroFlag() == false);
}

void testZeroFlag()
{
    ALU32 alu {};

    alu.setA(10)
       .setB(10)
       .setOperation(ALU32::Operation::SUB);

    assert(alu.getResult() == 0);
    assert(alu.getZeroFlag() == true);
}

void testAND()
{
    ALU32 alu {};

    alu.setA(0b1100)
       .setB(0b1010)
       .setOperation(ALU32::Operation::AND);

    assert(alu.getResult() == 0b1000);
}

void testOR()
{
    ALU32 alu {};

    alu.setA(0b1100)
       .setB(0b1010)
       .setOperation(ALU32::Operation::OR);

    assert(alu.getResult() == 0b1110);
}

void testXOR()
{
    ALU32 alu {};

    alu.setA(0b1100)
       .setB(0b1010)
       .setOperation(ALU32::Operation::XOR);

    assert(alu.getResult() == 0b0110);
}

void testShiftLeft()
{
    ALU32 alu {};

    alu.setA(1)
       .setB(4)
       .setOperation(ALU32::Operation::SHIFT_LEFT);

    assert(alu.getResult() == 16);
}

void testShiftRight()
{
    ALU32 alu {};

    alu.setA(16)
       .setB(3)
       .setOperation(ALU32::Operation::SHIFT_RIGHT);

    assert(alu.getResult() == 2);
}

void testNOP()
{
    ALU32 alu {};

    alu.setA(10)
       .setB(5)
       .setOperation(ALU32::Operation::NOP);

    assert(alu.getResult() == 0);
    assert(alu.getZeroFlag() == true);
}

void testChaining()
{
    ALU32 alu {};

    ALU32& result = alu.setA(10)
                      .setB(5)
                      .setOperation(ALU32::Operation::ADD);

    assert(&result == &alu);
    assert(alu.getResult() == 15);
}

void testDifferentWidths()
{
    ALU16 alu {};

    alu.setA(100)
       .setB(50)
       .setOperation(ALU16::Operation::ADD);

    assert(alu.getResult() == 150);
}

void testStaticCounter()
{
    ALU32 alu1 {};
    ALU32 alu2 {};

    const int initialCount = ALU32::getOperationCount();

    alu1.setA(10);

    assert(ALU32::getOperationCount() == initialCount + 1);

    alu2.setB(5);

    assert(ALU32::getOperationCount() == initialCount + 2);
}

void testStaticCountersArePerSpecialization()
{
    const int initial32Count = ALU32::getOperationCount();
    const int initial16Count = ALU16::getOperationCount();

    ALU32 alu32 {};
    ALU16 alu16 {};

    alu32.setA(10);
    alu16.setA(10);

    assert(ALU32::getOperationCount() == initial32Count + 1);
    assert(ALU16::getOperationCount() == initial16Count + 1);
}

int main()
{
    testDefaultState();
    testAddition();
    testSubtraction();
    testZeroFlag();

    testAND();
    testOR();
    testXOR();

    testShiftLeft();
    testShiftRight();

    testNOP();

    testChaining();

    testDifferentWidths();

    testStaticCounter();
    testStaticCountersArePerSpecialization();

    std::cout << "All tests passed.\n";

    return 0;
}