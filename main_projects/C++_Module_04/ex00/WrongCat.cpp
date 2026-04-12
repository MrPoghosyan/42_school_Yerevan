#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat defoult constructed!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat copied!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow**********" << std::endl;
}
