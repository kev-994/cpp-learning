#pragma once

#include <iostream>
#include <string>

template <typename T>
class ALU;

template <typename T>
class ALU
{
public:
    inline static int s_operationCount {};

    static int getOperationCount()
    {
        return s_operationCount;
    }

    enum class Operation
    {
        NOP,
        ADD,
        SUB,
        AND,
        OR,
        XOR,
        SHIFT_LEFT,
        SHIFT_RIGHT,
    };

    ALU& setA(T value);
    ALU& setB(T value);
    ALU& setOperation(Operation operation);

    T getResult() const { return m_result; }
    bool getZeroFlag() const { return m_zeroFlag; }

    friend void printALU<T>(const ALU<T>& alu);

private:
    // inputs
    T m_A {};
    T m_B {};
    Operation m_operation { Operation::NOP };

    // outputs
    T m_result {};
    bool m_zeroFlag {};

    // execution
    void executeOperation(); // executes when any input changes
    void setZeroFlag();
};


// INTERFACE

template <typename T>
ALU<T>& ALU<T>::setA(T value)
{
    m_A = value;
    executeOperation();
    return *this;
}

template <typename T>
ALU<T>& ALU<T>::setB(T value)
{
    m_B = value;
    executeOperation();
    return *this;
}

template <typename T>
ALU<T>& ALU<T>::setOperation(Operation operation)
{
    m_operation = operation;
    executeOperation();
    return *this;
}

template <typename T>
void printALU(const ALU<T>& alu)
{
    std::string operation {};

    switch (alu.m_operation)
    {
    case ALU<T>::Operation::NOP:
        operation = "NOP";
        break;

    case ALU<T>::Operation::ADD:
        operation = "ADD";
        break;

    case ALU<T>::Operation::SUB:
        operation = "SUB";
        break;

    case ALU<T>::Operation::AND:
        operation = "AND";
        break;

    case ALU<T>::Operation::OR:
        operation = "OR";
        break;

    case ALU<T>::Operation::XOR:
        operation = "XOR";
        break;

    case ALU<T>::Operation::SHIFT_LEFT:
        operation = "SHIFT LEFT";
        break;

    case ALU<T>::Operation::SHIFT_RIGHT:
        operation = "SHIFT RIGHT";
        break;
    }

    std::cout << "INPUTS:\n"
              << "A = " << alu.m_A << '\n'
              << "B = " << alu.m_B << '\n'
              << "Operation = " << operation << '\n'
              << "OUTPUTS:\n"
              << "RES = " << alu.m_result << '\n'
              << "ZF = " << alu.m_zeroFlag << '\n';
}


// IMPLEMENTATION

template <typename T>
void ALU<T>::setZeroFlag()
{
    m_zeroFlag = (m_result == 0);
}

template <typename T>
void ALU<T>::executeOperation()
{
    switch (m_operation)
    {
    case Operation::NOP:
        m_result = 0;
        break;

    case Operation::ADD:
        m_result = m_A + m_B;
        break;

    case Operation::SUB:
        m_result = m_A - m_B;
        break;

    case Operation::AND:
        m_result = m_A & m_B;
        break;

    case Operation::OR:
        m_result = m_A | m_B;
        break;

    case Operation::XOR:
        m_result = m_A ^ m_B;
        break;

    case Operation::SHIFT_LEFT:
        m_result = m_A << m_B;
        break;

    case Operation::SHIFT_RIGHT:
        m_result = m_A >> m_B;
        break;
    }

    setZeroFlag();

    ++s_operationCount;
}