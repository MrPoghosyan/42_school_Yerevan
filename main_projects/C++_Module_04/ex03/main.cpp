#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	AMateria * m1 = new Ice();
	AMateria * c1 = m1->clone();
	(void)c1;
	return 0;
}
