#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Static form creators
static AForm* createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

// Registry of available forms
const Intern::FormEntry Intern::_formRegistry[] = {
        {"shrubbery creation", &createShrubberyForm},
        {"robotomy request", &createRobotomyForm},
        {"presidential pardon", &createPresidentialForm}
};

const int Intern::_registrySize = sizeof(_formRegistry) / sizeof(_formRegistry[0]);

// Constructors and Destructor
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern assignment operator called" << std::endl;

	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// Make Form
AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	for (int i = 0; i < _registrySize; ++i)
	{
		if (_formRegistry[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return _formRegistry[i].creator(target);
		}
	}

	throw FormNotFoundException();
}

// Exception
const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found!";
}
