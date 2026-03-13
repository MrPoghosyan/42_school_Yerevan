#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon& weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		void attack();
};

#endif /* HUMANA_HPP */
