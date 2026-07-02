#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
        : AForm("ShrubberyCreationForm", 145, 137),
          _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
        : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
        : AForm(other), _target(other._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                _target = other._target;
        }
        return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
        checkExecution(executor);

        std::string filename = _target + "_shrubbery";
        std::ofstream file(filename.c_str());
        if (!file.is_open())
        {
                std::cerr << "Error: Could not create file "
                                  << filename << std::endl;
                return;
        }

        file << "              v .   ._, |_  .," << std::endl;
        file << "           `-._\\/  .  \\ /    |/_" << std::endl;
        file << "               \\\\  _\\, y | \\//" << std::endl;
        file << "         _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
        file << "           `7-,--.`._||  / / ," << std::endl;
        file << "           /'     `-. `./ / |/_.'" << std::endl;
        file << "                     |    |//" << std::endl;
        file << "                     |_    /" << std::endl;
        file << "                     |-   |" << std::endl;
        file << "                     |   =|" << std::endl;
        file << "                     |    |" << std::endl;
        file << "--------------------/ ,  . \\--------._" << std::endl;

        file.close();
}
