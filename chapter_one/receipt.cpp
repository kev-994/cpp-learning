#include <iostream>
#include <string>
// This is a receipt for bossman's shop
int main()
{
	std::string shop{"Tasty Chicken & Pizza"};
	std::string customer{};
	
	// Food or drink and their prices
	std::string food1{"4 Wings and Chips"};
	double priceFood1{3.00};
	std::string food2{"Chicken Strip Burger"};  
	double priceFood2{3.50};
	std::string drink1{"Mirinda Strawberry"};
	double priceDrink1{0.79};
	double subtotal{priceFood1 + priceFood2 + priceDrink1};

	bool deal{false};

	// Printing actual receipt
	std::cout << "===========" << "\n";
	std::cout << "  RECEIPT	 " << "\n";
	std::cout << "===========" << "\n\n\n";

	std::cout << "Yes boss, what is your name? ";
	std::cin >> customer;
	std::cout << "\n";
	
	std::cout << "Shop: " << shop << "\n";
	std::cout << "Customer: " << customer << "\n";
	std::cout << " - " << food1 << " £" << priceFood1 << "\n";
	std::cout << " - " << food2 << " £" << priceFood2 << "\n";
	std::cout << " - " << drink1 << " £" << priceDrink1 << "\n\n";
	
	std::cout << "Subtotal: £" << subtotal << "\n";
	std::cout << "Deal applied: " << deal << "\n";
	std::cout << "Final total: £" << subtotal << "\n";
	
	return 0;   
}
