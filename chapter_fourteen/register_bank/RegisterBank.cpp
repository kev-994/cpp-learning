#include "RegisterBank.h"
#include <iostream>
#include <format>

std::optional<std::uint32_t> RegisterBank::read(std::uint32_t address) const // 
{
    if (control.getAddress() == address) return control.read();
    else if (status.getAddress() == address) return status.read();
    else if (data.getAddress() == address) return data.read();
    else if (config.getAddress() == address) return config.read();
    else return std::nullopt;
}

WriteResult RegisterBank::write(std::uint32_t address, std::uint32_t value)
{
    using enum WriteResult;
    if (control.getAddress() == address) 
    {
        return control.write(value) ? Success : ReadOnly;
    }
    else if (status.getAddress() == address)
    {
        return status.write(value) ? Success : ReadOnly;
    }
    else if (data.getAddress() == address)
    { 
        return data.write(value) ? Success : ReadOnly;
    }
    else if (config.getAddress() == address)
    {
        return config.write(value) ? Success : ReadOnly;
    }
    else return InvalidAddress;
}

std::string RegisterBank::formatRegister(const Register& reg) const
{
    auto value {reg.read()};
    const auto& name {reg.getName()};
    return std::format("0x{:02X}", reg.getAddress()) + std::string(5, ' ') +  name +  std::string(name.length() < 9 ? 9 - name.length() : 0, ' ') + (value ? std::format("0x{:08X}", *value) : "NON-READABLE") + " " + std::string{reg.getPermissions()} + '\n';
    
}

void RegisterBank::displayRegisters() const
{
    std::cout << "Address  " << "Name     " << "Value      " << "Permissions\n" 
              << formatRegister(control)
              << formatRegister(status)
              << formatRegister(data)
              << formatRegister(config)
              << '\n';
}