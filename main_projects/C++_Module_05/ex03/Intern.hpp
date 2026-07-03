#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	private:
		typedef AForm* (*FormCreator)(const std::string &target);

		struct FormEntry
		{
			const char *name;
			FormCreator creator;
		};

		static const FormEntry _formRegistry[];
		static const int _registrySize;

	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm* makeForm(const std::string &formName, const std::string &target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif /* INTERN_HPP */
