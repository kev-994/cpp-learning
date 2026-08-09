#include <iostream>
#include <string_view>

enum class ALUOperation
{
    Load,
    Add,
    Subtract,
    And,
    Or,
    Xor
};

constexpr std::string_view getOpName(ALUOperation operation)
{
    using enum ALUOperation;
    switch (operation)
    {
    case Load:     return "Load";
    case Add:      return "Add";
    case Subtract: return "Subtract";
    case And:      return "And";
    case Or:       return "Or";
    case Xor:      return "Xor";
    default:       return "???";
    }
}

int main()
{
    while (true)
    {
        std::cout << "Enter ALU operation (0-5) or -1 to exit: ";
        int userOp {};
        std::cin >> userOp;

        if (userOp == -1) return 0;

        ALUOperation operation {static_cast<ALUOperation>(userOp)};

        std::cout << "Operation: " << getOpName(operation) << '\n'
                << "Opcode: " << static_cast<int>(operation) << '\n'; 
    }             
    return 0;
}