#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip> // setw
#include <limits>

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact contacts[8];
		int totalContacts;

	public:
		bool displayContacts() const;
		void viewContact(int index) const;
		void addContact();
		bool searchIndex(int &index);
		PhoneBook();

	private:
		std::string truncate_10(const std::string &str) const;

};

bool	askNonEmpty(const std::string &prompt, std::string &field);
bool	isValidPhone(const std::string& str);
bool	isValidAlpha(const std::string& str);

#endif
