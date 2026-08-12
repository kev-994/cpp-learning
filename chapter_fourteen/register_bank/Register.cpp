#include "Register.h"
#include <iostream>


Register::Register(std::uint32_t address, const std::string& name, bool readable, bool writeable)
        : m_address {address}
        , m_name {name}
        , m_readable {readable}
        , m_writeable {writeable}
        {}

std::optional<std::uint32_t> Register::read() const // 
{
    if (m_readable)
        return m_value;
    return std::nullopt;
}

bool Register::write(std::uint32_t value)
{
    if (m_writeable)
    {    
        m_value = value;
        return true;
    }
    return false;
}

std::uint32_t Register::getAddress() const
{
    return m_address;
}

const std::string& Register::getName() const
{
    return m_name;
}

std::string_view Register::getPermissions() const
{
    if (m_readable && m_writeable) return "R/W";
    else if (m_readable) return "R";
    else if (m_writeable) return "W";
    else return "";
}