#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter first name: ";
    std::string firstName{};
    std::cin >> firstName;
    
    std::cout << "Enter surname: ";
    std::string surname{};
    std::cin >> surname;

    std::cout << "Enter year of birth: ";
    int year{};
    std::cin >> year;

    constexpr char separator{'_'};

    std::string username{firstName + surname + separator + std::to_string(year)};

    std::cout << "\n" << "Generated username: " << username << "\n";
    
    return 0;
}