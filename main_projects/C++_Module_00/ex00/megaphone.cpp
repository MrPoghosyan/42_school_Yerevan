#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int j = 1; j < argc; ++j)
	{
		std::string s(argv[j]);
		for (size_t i = 0; i < s.length(); ++i){
			std::cout << static_cast<char>(
					std::toupper(static_cast<unsigned char>(s[i]))
					);
		}
		if (j < argc -1)
			std::cout << " ";
	}
	std::cout << "\n";
	return 0;
}
