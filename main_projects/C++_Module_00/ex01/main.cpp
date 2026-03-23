#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	int index;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)){
			std::cout << std::endl;
			break;
		}
/*
		for (size_t i = 0; i < command.length(); ++i)
			command[i] = std::toupper(static_cast<unsigned char>(command[i]));
*/
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH") {
			if (phonebook.displayContacts()) {
				if (phonebook.searchIndex(index))
					phonebook.viewContact(index);
			}
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}
