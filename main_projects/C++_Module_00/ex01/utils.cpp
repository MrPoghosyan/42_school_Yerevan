#include "PhoneBook.hpp"

bool	askNonEmpty(const std::string &prompt, std::string &field)
{
	bool onlySpaces;

	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, field))
			return false;
		onlySpaces = true;
		for (size_t i = 0; i < field.length(); ++i){
			if (!std::isspace(static_cast<unsigned char>(field[i]))){
				onlySpaces = false;
				break;
			}
		}
		if (!onlySpaces)
			return true;
		std::cout << prompt << "Field cannot be empty!" << std::endl;
	}
}

bool	isValidPhone(const std::string& str)
{
	bool hasDigit = false;
	char c;

	for (size_t i = 0; i < str.length(); ++i){
		c = str[i];

		if (std::isdigit(static_cast<unsigned char>(c)))
			hasDigit = true;
		else if (c == '+' && i == 0)
			continue;
		else if (c == '-' || c == ' ' || c == '(' || c == ')')
			continue;
		else
			return false;
	}
	return hasDigit;
}

bool isValidAlpha(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i){
		if (!std::isalpha(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}
