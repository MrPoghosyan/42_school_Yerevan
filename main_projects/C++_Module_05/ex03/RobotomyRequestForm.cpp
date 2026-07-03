#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
        : AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
        : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
        : AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                _target = other._target;
        }
        return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
        checkExecution(executor);

        std::cout << "* DRILLING NOISES *" << std::endl;
        std::cout << "* BZZZZZZZZZ *" << std::endl;
        std::cout << "* GRRRRRRRR *" << std::endl;

        static bool seeded = false;
        if (!seeded)
        {
                srand(time(NULL));
                seeded = true;
        }

        if (rand() % 2 == 0)
                std::cout << _target << " has been robotomized successfully!" << std::endl;
        else
                std::cout << _target << " robotomy failed!" << std::endl;
}
