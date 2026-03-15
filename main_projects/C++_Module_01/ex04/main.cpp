#include "header.hpp"

int main(int argc, char** argv)
{
	if (argc != 4){
		std::cerr << "Usage: ./replace filename s1 s2\n";
		return 1;
	}

	std::string filename = argv[1];
	if (check_empty(filename, "filename"))
		return 1;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (check_empty(s1, "s1") || check_empty(s2, "s2"))
		return 1;

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Error opening file\n";
		return 1;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error creating output file\n";
		return 1;
	}

	if (!ft_replace(infile, outfile, s1, s2))
		return 1;

	return 0;
}
