#include <iostream>
#include <string>


int getStartingNumber()
{
	return 994;
}

int getIntermediateNumber()
{
	return getStartingNumber();
}

int getFinalNumber()
{
	return getIntermediateNumber();
}

std::string getMessage()
{
	return "Da Boss";
}

int main()
{
	int num {getFinalNumber()} ;
	std::string message {getMessage()} ;

	std::cout << "Message: " << message << "\n";
	std::cout << "Number: "  << num   << "\n";
	
	return 0;
}
