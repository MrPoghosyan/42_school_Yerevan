#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(),
	  ScavTrap(),
	  FragTrap(),
	  _name("default")
{
	_hitPoints		= 100; // FragTrap
	_energyPoints	= 50;  // ScavTrap
	_attackDamage	= 30;  // FragTrap
	
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  _name(name)
{
	_hitPoints		= 100; // FragTrap
	_energyPoints	= 50;  // ScavTrap
	_attackDamage	= 30;  // FragTrap

	std::cout << "DiamondTrap " << _name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other),
	  _name(other._name)
{
	std::cout << "DiamondTrap copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << "\n"
			  << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
