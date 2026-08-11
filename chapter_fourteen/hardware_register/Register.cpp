#include "Register.h"

void Register::write(std::uint16_t value)
{
    m_value = value;
}

std::uint16_t Register::read() const
{
    return m_value;
}