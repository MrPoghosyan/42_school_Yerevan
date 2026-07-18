#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	BitcoinExchange	exchange;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		exchange.loadDatabase("data.csv");
		exchange.processInput(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
