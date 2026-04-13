#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	std::cout << "Cat defoult constructed!" << std::endl;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat& other)
	: Animal(other),
	  brain(new Brain(*other.brain))
{
	std::cout << "Cat copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator." << std::endl;
	
	if (this != &other)
	{
		Animal::operator=(other);

		Brain* tmp = new Brain(*other.brain);
		delete brain;
		brain = tmp;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow**********" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}
