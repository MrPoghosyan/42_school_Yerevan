#include "functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int choice = std::rand() % 3;

	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != 0)
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

/*
** No pointer allowed inside this overload: dynamic_cast to a reference
** throws (instead of returning NULL) when the cast is invalid, so we
** rely on try/catch to figure out the real type. Catching with "..."
** avoids naming std::bad_cast, which would require <typeinfo>.
*/
void identify(Base &p)
{
	try
	{
		A &ref = dynamic_cast<A &>(p);
		(void)ref;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		B &ref = dynamic_cast<B &>(p);
		(void)ref;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		C &ref = dynamic_cast<C &>(p);
		(void)ref;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...)
	{
		std::cout << "unknown" << std::endl;
	}
}
