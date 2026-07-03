#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
        try
        {
                std::cout << "\n=== Testing Intern with valid forms ===" << std::endl;
                Intern intern;
                AForm* form;
                
                // Test ShrubberyCreationForm
                form = intern.makeForm("shrubbery creation", "garden");
                std::cout << *form << std::endl;
                delete form;
                std::cout << std::endl;
                
                // Test RobotomyRequestForm
                form = intern.makeForm("robotomy request", "Bender");
                std::cout << *form << std::endl;
                delete form;
                std::cout << std::endl;
                
                // Test PresidentialPardonForm
                form = intern.makeForm("presidential pardon", "Ford Prefect");
                std::cout << *form << std::endl;
                delete form;
                std::cout << std::endl;
                
                std::cout << "=== Testing Intern with invalid form ===" << std::endl;
                try
                {
                        form = intern.makeForm("invalid form", "target");
                        delete form; // Should never reach here
                }
                catch (const Intern::FormNotFoundException &e)
                {
                        std::cerr << "Error: " << e.what() << std::endl;
                }
                std::cout << std::endl;
                
                std::cout << "=== Testing full workflow with Intern ===" << std::endl;
                Bureaucrat boss("Boss", 1);
                Bureaucrat trainee("Trainee", 150);
                
                form = intern.makeForm("robotomy request", "Marvin");
                std::cout << *form << std::endl;
                
                boss.signForm(*form);
                boss.executeForm(*form);
                
                delete form;
                std::cout << std::endl;
                
                std::cout << "=== Testing Intern copy ===" << std::endl;
                Intern intern2(intern);
                Intern intern3;
                intern3 = intern;
                (void)intern2;
                (void)intern3;
        }
        catch (std::exception &e)
        {
                std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        return 0;
}
