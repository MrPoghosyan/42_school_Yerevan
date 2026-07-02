#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
        try
        {
                // Create bureaucrats
                Bureaucrat bob("Bob", 1);
                Bureaucrat alice("Alice", 50);
                Bureaucrat charlie("Charlie", 150);

                std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
                ShrubberyCreationForm shrub("home");
                std::cout << shrub << std::endl;
                
                bob.signForm(shrub);
                bob.executeForm(shrub);
                std::cout << std::endl;

                std::cout << "=== Testing RobotomyRequestForm ===" << std::endl;
                RobotomyRequestForm robot("Bender");
                std::cout << robot << std::endl;
                
                alice.signForm(robot);
                alice.executeForm(robot);
                std::cout << std::endl;

                std::cout << "=== Testing PresidentialPardonForm ===" << std::endl;
                PresidentialPardonForm pardon("Ford Prefect");
                std::cout << pardon << std::endl;
                
                bob.signForm(pardon);
                bob.executeForm(pardon);
                std::cout << std::endl;

                std::cout << "=== Testing with insufficient grade ===" << std::endl;
                PresidentialPardonForm pardon2("Arthur Dent");
                charlie.signForm(pardon2);
                charlie.executeForm(pardon2);
                std::cout << std::endl;

                std::cout << "=== Testing unsigned form ===" << std::endl;
                RobotomyRequestForm robot2("Marvin");
                alice.executeForm(robot2); // Should fail - form not signed
        }
        catch (std::exception &e)
        {
                std::cerr << "Exception: " << e.what() << std::endl;
        }

        return 0;
}
