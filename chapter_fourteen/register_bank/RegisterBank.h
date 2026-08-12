#pragma once
#include "Register.h"

enum class WriteResult
{
    Success,
    InvalidAddress,
    ReadOnly
};

class RegisterBank
{
public:   
    std::optional<std::uint32_t> read(std::uint32_t address) const;
    WriteResult write(std::uint32_t address, std::uint32_t value);
    void displayRegisters() const;

private:
    std::string formatRegister(const Register& reg) const;

    Register control {0x00, "CONTROL", true, true};
    Register status  {0x04, "STATUS", true, false};
    Register data    {0x08, "DATA", true, true};
    Register config  {0x0C, "CONFIG", true, true};

};

