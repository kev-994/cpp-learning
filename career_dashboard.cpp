#include <iostream>
#include <string>
// This is my career dashboard
int main()
{
	std::string name;
	name = "Kevin Magombe";
	
	int age{19};

	std::string goal;
	goal = "Hardware Engineer at HFT firm, big tech etc.";

	bool isInterested;
	isInterested = true;

	std::string university;
	university = "Cambridge";

	int salary{120000};

		

	std::cout << "Road to money\n" << "=============\n";
	std::cout << "\n" <<  "Name: " << name << "\n";
	std::cout << "Age: " << age << "\n";
	std::cout << "Goal: " << goal << "\n";
	std::cout << "Want to make bank after uni? " << isInterested << "\n";
	std::cout << "University: " << university << "\n";
	std::cout << "What is your dream grad salary? £" << salary << "\n"; 
	return 0;
}
// Can just initialise everything with curly braces
// Also remember to return, though not required in modern C++
