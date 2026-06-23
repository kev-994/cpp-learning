#include <iostream>
#include <string>

std::string getCharacterName()
{
	return "Jin Woo";
}

int getStartingHealth()
{
	return 100;
}

int doubleHealth(int health)
{
	return health * 2;
}

std::string getCharacterClass()
{
	return "S";
}


int calculateAttackPower(int health)
{
	return health * 5;
}

int main()
{
	std::cout << "=================" << "\n";
	std::cout << " CHARACTER SHEET " << "\n";
	std::cout << "=================" << "\n\n\n";	

	std::string name{getCharacterName()};
	std::cout << "Name: " << name << "\n";

	std::string charClass{getCharacterClass()};
	std::cout << "Class: " << charClass << "\n\n";

	int health{getStartingHealth()};
	std::cout << "Health: " << health << "\n";

	int boostedHealth{doubleHealth(health)};
	std::cout << "Boosted Health: " << boostedHealth << "\n";

	int attackPower{calculateAttackPower(health)};
	std::cout << "Attack Power: " << attackPower << "\n";

	return 0;
} 
