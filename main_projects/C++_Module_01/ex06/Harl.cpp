#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level )
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int levelIndex = 0;
	while (levelIndex < 4 && level != levels[levelIndex])
		levelIndex++;

	switch (levelIndex)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			debug();
			// fallthrough
		case 1:
			std::cout << "[ INFO ]\n";
			info();
			// fallthrough
		case 2:
			std::cout << "[ WARNING ]\n";
			warning();
			// fallthrough
		case 3:
			std::cout << "[ ERROR ]\n";
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
