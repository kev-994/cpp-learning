#include "Register.h"

#include <iostream>
#include <cstdint>
#include <format>
#include <cassert>

Register operator+(const Register& reg1, const Register& reg2)
{
    return reg1.m_value + reg2.m_value;
}

Register operator-(const Register& reg1, const Register& reg2)
{
    return reg1.m_value - reg2.m_value;
}

Register operator&(const Register& reg1, const Register& reg2)
{
    return reg1.m_value & reg2.m_value;
}

Register operator|(const Register& reg1, const Register& reg2)
{
    return reg1.m_value | reg2.m_value;
}

Register operator^(const Register& reg1, const Register& reg2)
{
    return reg1.m_value ^ reg2.m_value;
}

bool operator==(const Register& reg1, const Register& reg2)
{
    return reg1.m_value == reg2.m_value;
}

bool operator!=(const Register& reg1, const Register& reg2)
{
    return !(reg1 == reg2);
}

Register& Register::operator++()
{
    ++m_value;
    return *this;
}

Register& Register::operator--()
{
    --m_value;
    return *this;
}

Register Register::operator++(int)
{
    auto temp{*this};
    ++(*this);
    return temp;
}

Register Register::operator--(int)
{
    auto temp{*this};
    --(*this);
    return temp;
}

bool Register::operator[](int bit) const
{
    assert(bit >= 0 && bit <= 32);
    return (m_value >> bit) & 1;
}

std::ostream& operator<<(std::ostream& out, const Register& reg1)
{
    out << std::format("0x{:08X}", reg1.m_value);
    return out;
}

Register::operator uint32_t() const
{
    return m_value;
}



