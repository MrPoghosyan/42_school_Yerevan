#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	// Member functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// For debugging / checking status
	void status() const;
};

#endif
