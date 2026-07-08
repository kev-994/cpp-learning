/*
Student Record
--------------
Name: Kevin Magombe
Course: Engineering
University: University of Cambridge
Start year: 2025
Graduation year: 2029
Study length: 4 years
Reference code: Kevin Magombe_2025_2029
*/

#include <iostream>
#include <string>

std::string getInfo(std::string str)
{
    std::cout << "Enter " << str << ": ";
    std::string info{};
    std::getline(std::cin >> std::ws, info);

    return info;
}

int getYear(std::string str)
{
    std::cout << "Enter " << str << ": ";
    int year{};
    std::cin >> year;

    return year;
}

void printInfo(std::string str, std::string info)
{
    std::cout << str << ": " << info << "\n"; 
}

int main()
{
    std::string fullName{getInfo("full name")};
    std::string course{getInfo("course")};
    std::string university{getInfo("university")};
    
    int startYear{getYear("start year")};
    int graduationYear{getYear("expected graduation year")};


    if (startYear >= graduationYear)
    {   
        std::cout << "\nInvalid graduation year\n";
        return 1;
    }
    
    int studyLength{graduationYear - startYear};

    constexpr char separator{'_'};

    std::string referenceCode{fullName + separator + std::to_string(startYear) + separator + std::to_string(graduationYear)};

    std::cout << "Student Record\n";
    std::cout << "--------------\n\n";

    printInfo("Full name", fullName);
    printInfo("Course", course);
    printInfo("University", university);
    printInfo("Start year", std::to_string(startYear));
    printInfo("Graduation year", std::to_string(graduationYear));
    printInfo("Study length", std::to_string(studyLength));
    printInfo("Reference code", referenceCode);

    return 0;
}