#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat d;
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	try
	{
		Bureaucrat a("Bob", 2);
		std::cout << a << std::endl;

		a.incrementGrade(); // OK → 1
		std::cout << a << std::endl;

		a.incrementGrade(); // ❌ exception
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	try
	{
		Bureaucrat c("Jon", 149);
		std::cout << c << std::endl;

		c.decrementGrade(); // OK → 1
		std::cout << c << std::endl;

		c.decrementGrade(); // ❌ exception
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;

	try
	{
		Bureaucrat b("Alice", 151); // ❌ exception
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
