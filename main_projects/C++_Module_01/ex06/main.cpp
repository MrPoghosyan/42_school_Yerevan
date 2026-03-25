#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error!\nUsage: ./harlFilter level.\n";
		return 1;
	}
	std::string level = argv[1];
	if (level.empty())
	{
		std::cerr << "Error: level cannot be empty!\n";
		return 1;
	}
	
	Harl harl;
	harl.complain(level);

	return 0;
}
