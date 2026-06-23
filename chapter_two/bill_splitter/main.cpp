#include "bill.h"
#include <iostream>

int main()
{
	printHeader();
	
	std::cout << "Enter meal cost: ";
	double mealCost{};
	std::cin >> mealCost;

	std::cout << "Enter service percentage: ";
	double servicePercent{};
	std::cin >> servicePercent;

	std::cout << "Enter number of people: ";
	int numberOfPeople{};
	std::cin >> numberOfPeople;
	
	double serviceCharge{getServiceCharge(mealCost, servicePercent)};
	double totalBill{getTotalBill(mealCost, serviceCharge)};
	double costPerPerson{getCostPerPerson(totalBill, numberOfPeople)};
		
	std::cout << "\n\n";

	printMoneyLine("Meal cost", mealCost);
	printMoneyLine("Service charge", serviceCharge);
	printMoneyLine("Total bill", totalBill);
	printMoneyLine("Cost per person", costPerPerson);

	return 0;
}
