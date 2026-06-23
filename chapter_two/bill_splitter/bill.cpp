#include "bill.h"
#include <iostream>
#include <string>
#include <iomanip>

void printHeader()
{
	std::cout << "=================\n";
	std::cout << "  BILL SPLITTER  " << "\n";  
	std::cout << "=================\n\n\n";
}

double getServiceCharge(double mealCost, double servicePercent)
{
	return mealCost * servicePercent / 100;
}

double getTotalBill(double mealCost, double serviceCharge)
{
	return mealCost + serviceCharge;
}

double getCostPerPerson(double totalBill, int numberOfPeople)
{
	return totalBill / numberOfPeople;
}

void printMoneyLine(std::string label, double amount)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << label << ": £" << amount << "\n";
}
