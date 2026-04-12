#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "=== BASIC TESTS ===\n" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog; // should not create a leak
    delete cat;

    std::cout << "\n=== ARRAY OF ANIMALS TESTS ===\n" << std::endl;

    const int arr = 4;
    int i;
    Animal* animals[arr];

    for (i = 0; i < 2; ++i)
        animals[i] = new Dog();

    for (i = 2; i < arr; ++i)
        animals[i] = new Cat();

    for (i = 0; i < arr; ++i)
        delete animals[i];

    std::cout << "\n=== DEEP COPY TESTS ===\n" << std::endl;
{
    Dog original;
    original.setIdea(0, "Eat");

    Dog copy = original;
    copy.setIdea(0, "Sleep");

    std::cout << original.getIdea(0) << std::endl;
    std::cout << copy.getIdea(0) << std::endl;
}
    std::cout << "\n" << std::endl;
{
    Cat original;
    original.setIdea(0, "Eat");

    Cat copy = original;
    copy.setIdea(0, "Sleep");

    std::cout << original.getIdea(0) << std::endl;
    std::cout << copy.getIdea(0) << std::endl;
}
	std::cout << "\n===== END =====\n" << std::endl;
	return 0;
}
