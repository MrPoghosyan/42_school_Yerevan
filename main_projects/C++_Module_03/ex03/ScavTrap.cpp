#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap()
	: ClapTrap()
{
	_hitPoints		= 100;
	_energyPoints	= 50;
	_attackDamage	= 20;

	std::cout << "ScavTrap default constructor called!" << std::endl;
}

// Constructor with name
ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPoints		= 100;
	_energyPoints	= 50;
	_attackDamage	= 20;

	std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copied!" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);

	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

// Override attack
void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack!" << std::endl;
		return;
	}

	_energyPoints--;

	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
			  << " is now in Gate keeper mode!" << std::endl;
}
