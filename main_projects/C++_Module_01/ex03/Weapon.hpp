#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	std::string type;

	public:
		Weapon(std::string type);

		const std::string& getType() const;
		void setType(const std::string& type);
};

#endif /* WEAPON_HPP */
