#include "Zombie.hpp"

int main()
{
	int n = 5;

	Zombie* horde = zombieHorde(n, "Jon");

	std::cout << "New " << n << " zombie!" << std::endl;
	for (int i = 0; i < n; ++i){
		horde[i].announce();
	}
	std::cout << "\nDelete " << n << " zombie." << std::endl;
	delete[] horde;

	return 0;
}
