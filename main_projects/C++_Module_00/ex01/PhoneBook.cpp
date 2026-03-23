#include "PhoneBook.hpp"

PhoneBook::PhoneBook():totalContacts(0){}

std::string PhoneBook::truncate_10(const std::string &str)const{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

bool PhoneBook::displayContacts() const{
	if (totalContacts == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return false;
	}

	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < totalContacts; ++i){
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncate_10(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate_10(contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate_10(contacts[i].getNickname()) << std::endl;
	}
	return true;
}

void PhoneBook::viewContact(int index) const{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::addContact() {
	Contact c;
	int index;
	std::string input;

	while (true){
		if (!askNonEmpty("First name: ", input))
			return;
		if (isValidAlpha(input))
			break;
		std::cout << "Invalid First name! Only letters allowed." << std::endl;
	}
	c.setFirstName(input);
	while(true){
		if (!askNonEmpty("Last name: ", input))
			return;
		if (isValidAlpha(input))
			break;
		std::cout << "Invalid Last name! Only letters allowed." << std::endl;

	}
	c.setLastName(input);
	if (!askNonEmpty("Nickname: ", input))
		return;
	c.setNickname(input);
	while (true){
		if (!askNonEmpty("Phone number: ", input))
			return;
		if (isValidPhone(input))
			break;
		std::cout << "Invalid phone number!" << std::endl;
	}
	c.setPhoneNumber(input);
	if (!askNonEmpty("Darkest Secret: ", input))
		return;
	c.setDarkestSecret(input);
	index = totalContacts % 8;
	contacts[index] = c;
	if (totalContacts < 8)
		totalContacts++;
}

bool	PhoneBook::searchIndex(int &index){
	std::string input;
	int attempts = 0;
	const int maxAttempts = 3;

	while (attempts < maxAttempts){
		std::cout << "Enter index: ";

		if (!std::getline(std::cin, input)){
			std::cout << std::endl;
			return false; //EOF (Ctrl+D)
		}
		if (input.length() != 1 || !std::isdigit(input[0])){
			std::cout << "Invalid index!" << std::endl;
			attempts++;
			continue;
		}
		index = input[0] - '0';
		if (index < 0 || index >= totalContacts){
			std::cout << "Invalid index!" << std::endl;
			attempts++;
			continue;
		}
		return true; // valid index
	}
	std::cout << "3 failed attempts!" << std::endl;
	return false; // 3 failed attempts
}
