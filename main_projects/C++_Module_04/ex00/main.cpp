#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== BASIC TESTS ===\n" << std::endl;
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}
    std::cout << "\n=== WRONG TESTS ===\n" << std::endl;
{	
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();

	std::cout << meta->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	meta->makeSound();
	cat->makeSound(); // failed polimorfizm
/*
	WrongCat obj;
	obj.makeSound();
*/
	delete meta;
	delete cat;
}
	std::cout << "\n===== END =====\n" << std::endl;
	return 0;
}
