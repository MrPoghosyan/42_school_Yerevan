#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}

	/*
	std::cout << "Testing literal: \"" << argv[1] << "\"" << std::endl;
    std::cout << "Size: " << std::string(argv[1]).size() << std::endl;
	*/
	ScalarConverter::convert(argv[1]);
	return (0);
}
