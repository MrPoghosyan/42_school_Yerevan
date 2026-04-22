#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	Character a("A");
	a.equip(new Ice());

	a.unequip(0); 

	Character b = a;
	b.use(0, a);

    Character::cleanupDropped(); // 👈 SAFE CLEANUP
	return 0;
}
