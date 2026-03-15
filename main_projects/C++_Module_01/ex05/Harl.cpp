#include <iostream>
#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "DEBUG: Detailed diagnostic information useful for debugging and development.\n";
}

void Harl::info( void )
{
	std::cout << "INFO: General information about normal program execution.\n";
}

void Harl::warning( void )
{
	std::cout << "WARNING: Indicates a potential issue that may require attention.\n";
}

void Harl::error( void )
{
	std::cout << "ERROR: A critical problem occurred that requires immediate action.\n";
}

void Harl::complain( std::string level)
{
	t_map map[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++){
		if (level == map[i].level){
			(this->*map[i].func)();
			return;
		}
	}
}
/*
void Harl::complain( std::string level )
{
	//typedef member function pointer
	typedef void (Harl::*HarlMemFn)();

	HarlMemFn functions[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*functions[i])(); //call member function pointer
			break;
		}
	}
}
*/
