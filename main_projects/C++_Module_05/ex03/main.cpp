#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        std::cout << "\n========== INTERN TESTS ==========\n" << std::endl;

        Intern intern;
        AForm *form = NULL;

        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat trainee("Trainee", 150);

        //==========================================================
        std::cout << "=== Test 1: Create ShrubberyCreationForm ===" << std::endl;

        form = intern.makeForm("shrubbery creation", "garden");
        std::cout << *form << std::endl;
        delete form;

        //==========================================================
        std::cout << "\n=== Test 2: Create RobotomyRequestForm ===" << std::endl;

        form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;

        //==========================================================
        std::cout << "\n=== Test 3: Create PresidentialPardonForm ===" << std::endl;

        form = intern.makeForm("presidential pardon", "Ford Prefect");
        std::cout << *form << std::endl;
        delete form;

        //==========================================================
        std::cout << "\n=== Test 4: Invalid form ===" << std::endl;

        try
        {
            form = intern.makeForm("invalid form", "target");
            delete form;
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        //==========================================================
        std::cout << "\n=== Test 5: Full workflow ===" << std::endl;

        form = intern.makeForm("robotomy request", "Marvin");

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;

        //==========================================================
        std::cout << "\n=== Test 6: Execute unsigned form ===" << std::endl;

        form = intern.makeForm("shrubbery creation", "park");

        boss.executeForm(*form);

        delete form;

        //==========================================================
        std::cout << "\n=== Test 7: Low grade to sign ===" << std::endl;

        form = intern.makeForm("robotomy request", "HAL9000");

        trainee.signForm(*form);

        delete form;

        //==========================================================
        std::cout << "\n=== Test 8: Low grade to execute ===" << std::endl;

        form = intern.makeForm("presidential pardon", "Arthur Dent");

        boss.signForm(*form);
        trainee.executeForm(*form);

        delete form;

        //==========================================================
        std::cout << "\n=== Test 9: Robotomy randomness ===" << std::endl;

        form = intern.makeForm("robotomy request", "R2D2");

        boss.signForm(*form);

        for (int i = 0; i < 6; i++)
            boss.executeForm(*form);

        delete form;

        //==========================================================
        std::cout << "\n=== Test 10: Shrubbery file creation ===" << std::endl;

        form = intern.makeForm("shrubbery creation", "forest");

        boss.signForm(*form);
        boss.executeForm(*form);

        std::cout << "Check generated file: forest_shrubbery" << std::endl;

        delete form;

        //==========================================================
        std::cout << "\n=== Test 11: Polymorphism (AForm array) ===" << std::endl;

        AForm *forms[3];

        forms[0] = intern.makeForm("shrubbery creation", "home");
        forms[1] = intern.makeForm("robotomy request", "Bender");
        forms[2] = intern.makeForm("presidential pardon", "Zaphod");

        for (int i = 0; i < 3; i++)
        {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
        }

        for (int i = 0; i < 3; i++)
            delete forms[i];

        //==========================================================
        std::cout << "\n=== Test 12: Multiple forms ===" << std::endl;

        AForm *a = intern.makeForm("robotomy request", "A");
        AForm *b = intern.makeForm("robotomy request", "B");
        AForm *c = intern.makeForm("robotomy request", "C");

        boss.signForm(*a);
        boss.signForm(*b);
        boss.signForm(*c);

        boss.executeForm(*a);
        boss.executeForm(*b);
        boss.executeForm(*c);

        delete a;
        delete b;
        delete c;

        //==========================================================
        std::cout << "\n=== Test 13: Empty target ===" << std::endl;

        form = intern.makeForm("robotomy request", "");

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;

        //==========================================================
        std::cout << "\n=== Test 14: Wrong case ===" << std::endl;

        try
        {
            form = intern.makeForm("Robotomy Request", "Bender");
            delete form;
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        //==========================================================
        std::cout << "\n=== Test 15: Wrong form name ===" << std::endl;

        try
        {
            form = intern.makeForm("robotomy", "Bender");
            delete form;
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        //==========================================================
        std::cout << "\n=== Test 16: Copy constructor / Assignment ===" << std::endl;

        Intern intern2(intern);
        Intern intern3;

        intern3 = intern;

        (void)intern2;
        (void)intern3;

        std::cout << "Copy and assignment completed successfully." << std::endl;

        std::cout << "\n========== ALL TESTS FINISHED ==========\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
