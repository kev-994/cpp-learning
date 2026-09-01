#include <memory>
#include <print>

class Register
{
public:
    Register(int value)
        : m_value{value}
        {}
    
    auto get() const {return m_value;}
    void set(int value) {m_value = value;}
private:
    int m_value{};
};

class RegisterBank
{
public:
    RegisterBank(std::shared_ptr<Register> bank)
        : m_bank{bank}
        {}
    
    auto getRegister() const {return m_bank;} 

private:
    std::shared_ptr<Register> m_bank;
};

int main()
{
    auto reg1{std::make_shared<Register>(42)};
    std::println("{}", reg1->get());
    auto reg2{reg1};
    reg2->set(994);
    std::println("{}", reg1->get());
    std::println("{}{}\n", reg1.use_count(), reg2.use_count());

    RegisterBank bank1{std::make_shared<Register>(1)};
    RegisterBank bank2{bank1.getRegister()};
    bank2.getRegister()->set(994);
    std::println("{}", bank1.getRegister()->get());
    std::println("{}", bank2.getRegister().use_count()); // use count is 3 because of temporary shared pointer 
    
    return 0;
}