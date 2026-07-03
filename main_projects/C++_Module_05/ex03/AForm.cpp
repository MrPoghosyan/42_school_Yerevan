#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("default"),
	  _isSigned(false),
	  _signGrade(150),
	  _execGrade(150)
{}

AForm::AForm(const AForm& other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _signGrade(other._signGrade),
	  _execGrade(other._execGrade)
{}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name(name),
	  _isSigned(false),
	  _signGrade(signGrade),
	  _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();

	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;

	return *this;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (_isSigned)
		return;

	if (b.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecution(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();

	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

// Operator <<
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName()
		<< ", signed: " << (f.getSigned() ? "true" : "false")
		<< ", sign grade: " << f.getSignGrade()
		<< ", exec grade: " << f.getExecGrade();
	return out;
}

AForm::~AForm(){}
