#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		Form(const Form& other);
		Form(const std::string &name, int signGrade, int execGrade);
		Form& operator=(const Form& other);
		~Form();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(const Bureaucrat &b);

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

// operator <<
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif /* FORM_HPP */
