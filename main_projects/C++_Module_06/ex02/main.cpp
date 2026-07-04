#include "functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int i = 0; i < 6; ++i)
	{
		Base *p = generate();

		std::cout << "identify(Base*): ";
		identify(p);

		std::cout << "identify(Base&): ";
		identify(*p);

		std::cout << "---" << std::endl;
		delete p;
	}
	return (0);
}
