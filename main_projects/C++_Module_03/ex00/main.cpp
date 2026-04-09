#include "ClapTrap.hpp"

int main()
{
	ClapTrap def;
	def.status();

	ClapTrap cl4("CL4P-TP");

	ClapTrap clap(cl4);

	clap.status();
	clap.attack("Target Dummy");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.status();

	return 0;
}
