#include "Counter.h"


Counter::Counter(std::uint32_t value)
    : m_value {value}
    {

    }

void Counter::tick()
{
    ++m_value;
}

std::uint32_t Counter::value() const
{
    return m_value;
}