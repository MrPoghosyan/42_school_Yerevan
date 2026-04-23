#include "Character.hpp"

AMateria* Character::dropped[100] = {0};
int Character::_index = 0;

Character::Character()
	: _name("")
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(std::string const & name)
	: _name(name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(const Character& other)
	: _name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i){
			delete inventory[i];
			inventory[i] = NULL;
		}

		_name = other._name;
		
		for (int i = 0; i < 4; ++i){
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
	}

	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i){
		if (inventory[i] == NULL){
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx  < 0 || idx >= 4)
		return;

	if (inventory[idx]){
		if (_index < 100)
			dropped[_index++] = inventory[idx];
		else
			std::cout << "Index: >=100, buffer dropped overflow!" << std::endl;
	}

	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;

	if (inventory[idx])
		inventory[idx]->use(target);
}

void Character::cleanupDropped()
{
	for (int i = 0; i < _index; ++i)
	{
		if (dropped[i] != NULL){
			delete dropped[i];
			dropped[i] = NULL;
		}
	}
	_index = 0; //Double call security
}
