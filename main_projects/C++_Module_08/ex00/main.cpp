#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int>	vec;
	std::list<int>		lst;
	std::deque<int>		deq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i * 2);
		lst.push_back(i * 3);
		deq.push_back(i * 5);
	}

	try
	{
		std::vector<int>::iterator	it = easyfind(vec, 8);
		std::cout << "Found " << *it << " in vector." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator	it = easyfind(lst, 15);
		std::cout << "Found " << *it << " in list." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator	it = easyfind(deq, 25);
		std::cout << "Found " << *it << " in deque." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator	it = easyfind(vec, 999);
		std::cout << "Found " << *it << " in vector." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
