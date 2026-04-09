#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name(""),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap default constructors!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name			= other._name;
		_hitPoints		= other._hitPoints;
		_energyPoints	= other._energyPoints;
		_attackDamage	= other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack (no energy or hit points left)!" << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}

	if (amount >= (unsigned int)_hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage! Hit points left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself!" << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints -= 1;

	std::cout << "ClapTrap " << _name << " repairs itself for "
		<< amount << " points! Hit points: " << _hitPoints
		<< ", Energy points: " << _energyPoints << std::endl;
}

void ClapTrap::status() const
{
	std::cout << "ClapTrap " << _name
		<< " | HP: " << _hitPoints
		<< " | EP: " << _energyPoints
		<< " | AD: " << _attackDamage << std::endl;
}
