#include <iostream>
#include <string>
// Project status for the summer
int main()
{
	std::string phase_one{"C++, Linux and some SystemVerilog"};
	std::string phase_two{"RTL Design"};
	std::string phase_three{"CPU Project"};
	std::string grade{"First"};
	double hours_studied{};
	bool isComplete{false};
	
	std::cout << "==============\n";
	std::cout << "PROJECT STATUS\n";
	std::cout << "==============\n\n\n\n";	

	// What has been completed so far
	std::cout << "Phase 1: " << phase_one << "\n";
	std::cout << "Complete: " << isComplete << "\n\n";
	std::cout << "Phase 2: " << phase_two << "\n";
	std::cout << "Complete: " << isComplete << "\n\n";
	std::cout << "Phase 3: " << phase_three << "\n";
        std::cout << "Complete: " << isComplete << "\n\n\n"; 
	
	std::cout << "Expected first year grade: " << grade << "\n\n";
	std::cout << "How many hours did you study this week? ";
	std::cin >> hours_studied;
	std::cout << "You studied for " << hours_studied << " hours" << "\n";
	
	return 0;
}
