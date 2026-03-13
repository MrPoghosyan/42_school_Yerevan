#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:name(name), weapon(NULL)
{}

void HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " attacks with their "
				  << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
