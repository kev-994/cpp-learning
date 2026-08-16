#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    std::cout << "Number of 32-bit words to allocate: ";

    std::size_t len {};
    std::cin >> len;

    std::vector<std::uint32_t> buffer(len);

    while (true)
    {
        std::cout << "Enter index: ";
        int i {};
        std::cin >> i;

        if (i < 0 || i >= static_cast<int>(buffer.size()))
        {
            std::cout << "Invalid index\n";
            continue;
        }

        std::cout << "Enter value: ";
        std::uint32_t value {};
        std::cin >> value;

        buffer[i] = value;

        std::cout << "[";
        for (std::size_t i = 0; i < buffer.size(); i++)
        {
            std::cout << buffer[i];

            if (i < buffer.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";

        char choice {};
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;

        if (choice == 'n')
            break;
    }

    return 0;
}