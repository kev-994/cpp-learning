#ifndef BILL_H
#define BILL_H

#include <string>

void printHeader();

double getServiceCharge(double mealCost, double servicePercent);

double getTotalBill(double mealCost, double serviceCharge);

double getCostPerPerson(double totalBill, int numberOfPeople);

void printMoneyLine(std::string label, double amount);

#endif
