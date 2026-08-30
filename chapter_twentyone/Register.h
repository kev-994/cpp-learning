#pragma once

#include <iostream>
#include <cstdint>

class Register
{
public:
    Register(std::uint32_t value)
        : m_value{value}
        {}
    
    friend Register operator+(const Register& reg1, const Register& reg2);
    friend Register operator-(const Register& reg1, const Register& reg2);
    friend Register operator&(const Register& reg1, const Register& reg2);
    friend Register operator|(const Register& reg1, const Register& reg2);
    friend Register operator^(const Register& reg1, const Register& reg2);
    friend bool operator==(const Register& reg1, const Register& reg2);
    friend bool operator!=(const Register& reg1, const Register& reg2);
    friend std::ostream& operator<<(std::ostream& out, const Register& reg1);


    Register operator~() const {return ~m_value;}
    Register& operator++();
    Register& operator--();
    Register operator++(int);
    Register operator--(int);
    bool operator[](int bit) const;
    operator uint32_t() const;

private:
    std::uint32_t m_value{};
};