#pragma once
#include <cstdint>

class Register
{
public:
    using Value = std::uint32_t;    

    enum class Access
    {
        ReadOnly,
        ReadWrite
    };

    Register() = default;
    Register(Value value, Access access)
        : m_value {value}, m_access {access}
        {}

    Value read() const {return m_value;}
    void write(Value value);
    Register& reset(); // only resets value and not access 

private:
    Value m_value {};
    Access m_access {};
};