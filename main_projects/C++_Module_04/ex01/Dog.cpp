#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	std::cout << "Dog defoult constructed!" << std::endl;

	brain = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog& other)
	: Animal(other),
	  brain(new Brain(*other.brain))
{
	std::cout << "Dog copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator." << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);

		Brain* tmp = new Brain(*other.brain);
		delete brain;
		brain = tmp;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed!" << std::endl;
	delete brain;
	brain = NULL;
}

void Dog::makeSound() const
{
	std::cout << "Woof**********" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}
