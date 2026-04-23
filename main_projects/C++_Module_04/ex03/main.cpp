#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

/*
int main()
{
    {
        Character a("A");
        a.equip(new Ice());
        a.unequip(0);

        Character b = a;
        b.use(0, a);
        Character::cleanupDropped(); // for unequip();
    }

    IMateriaSource* src = new MateriaSource();
    AMateria* tmp = new Ice();
    src->learnMateria(tmp);
    delete tmp; //✔ caller cleans

    tmp = new Cure();
    src->learnMateria(tmp);
    delete tmp; //✔ caller cleans

    Character me("me");
    Character bob("bob");

    me.equip(src->createMateria("ice"));
    me.equip(src->createMateria("cure"));

    me.use(0, bob);
    me.use(1, bob);

    delete src;

    return 0;
}
*/
