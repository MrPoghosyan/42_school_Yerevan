#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "\n********** Memory Address **********" << std::endl;

	std::cout << "Memory address str:       " << &str << std::endl;
	std::cout << "Memory address stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address stringREF: " << &stringREF << std::endl;

	std::cout << "\n********** Variable Value **********" << std::endl;

	std::cout << "Str:       " << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << "\n" << std::endl;

	return 0;
}
