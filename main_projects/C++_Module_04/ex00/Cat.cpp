#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat defoult constructed!" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow**********" << std::endl;
}
