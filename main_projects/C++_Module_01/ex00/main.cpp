#include "Zombie.hpp"

int main()
{
    randomChump("Bar");

    Zombie* z = newZombie("Foo");
    z->announce();
    delete z;


    return 0;
}
