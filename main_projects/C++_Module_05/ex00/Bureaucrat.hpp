#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade; // Ranges from 1->150

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Getters
		const std::string	getName() const;
		int					getGrade() const;

		// Actions
		void		incrementGrade();
		void		decrementGrade();

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// operator<<
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif /* BUREAUCRAT_HPP */
