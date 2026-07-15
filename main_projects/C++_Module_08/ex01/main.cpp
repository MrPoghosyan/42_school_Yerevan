#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	Span	sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	Span	empty(3);
	try
	{
		empty.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	Span				big(10000);
	std::vector<int>	numbers;

	std::srand(42);
	for (int i = 0; i < 10000; i++)
		numbers.push_back(std::rand());
	big.addRange(numbers.begin(), numbers.end());
	std::cout << "Shortest span among 10000 numbers: " << big.shortestSpan() << std::endl;
	std::cout << "Longest span among 10000 numbers: " << big.longestSpan() << std::endl;

	try
	{
		big.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	Span oneElement(1);
	try
	{
		oneElement.addNumber(5);
		oneElement.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "One element: " << e.what() << std::endl;
	}

	Span duplicateNumbers(3);

	try
	{
		duplicateNumbers.addNumber(5);
		duplicateNumbers.addNumber(5);
		duplicateNumbers.addNumber(10);

		std::cout << duplicateNumbers.shortestSpan() << std::endl;// output = 0
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: Duplicate numbers." << e.what() << std::endl;
	}

	Span overflow(5);
	std::vector<int> v(10);
	for (int i = 0; i < 10; ++i)
		v[i] = i;

	try
	{
		overflow.addRange(v.begin(), v.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: Overflow." << e.what() << std::endl;
	}

	Span zero(0);

	try
	{
		std::cout << zero.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Zero capacity: " << e.what() << std::endl;
	}

	Span emptyRange(5);
	std::vector<int> emptyVec;

	try
	{
		emptyRange.addRange(emptyVec.begin(), emptyVec.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "Empty vector range: " << e.what() << std::endl;
	}

	return (0);
}
