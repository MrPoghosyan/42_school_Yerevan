#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		AForm();

	protected:
		void checkExecution(Bureaucrat const &) const;

	public:
		AForm(const AForm& other);
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		//virtual metod
		virtual void execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// operator <<
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif /* AFORM_HPP */
