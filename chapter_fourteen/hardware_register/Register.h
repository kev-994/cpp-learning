# pragma once
#include <cstdint>

class Register
{
public: 
    void write(std::uint16_t value);
    std::uint16_t read() const;
private:
    std::uint16_t m_value {};
};