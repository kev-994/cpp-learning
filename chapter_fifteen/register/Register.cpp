#include "Register.h"

void Register::write(Value value)
{
    if (m_access == Access::ReadWrite)
        m_value = value;
}

Register& Register::reset() 
    {
        m_value = {}; 
        return *this;
    }
