#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	PmergeMe	pmerge;

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		pmerge.run(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
