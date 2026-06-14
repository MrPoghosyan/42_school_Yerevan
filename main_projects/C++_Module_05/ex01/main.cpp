#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n========== TEST 1 : Valid Form ==========\n";
    try
    {
        Form f("Tax Form", 20, 30);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 2 : signGrade = 0 ==========\n";
    try
    {
        Form f("BadForm", 0, 30);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 3 : execGrade = 0 ==========\n";
    try
    {
        Form f("BadForm", 10, 0);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 4 : signGrade = 151 ==========\n";
    try
    {
        Form f("BadForm", 151, 10);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 5 : execGrade = 151 ==========\n";
    try
    {
        Form f("BadForm", 10, 151);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 6 : Successful Sign ==========\n";
    try
    {
        Bureaucrat bob("Bob", 10);
        Form form("Contract", 20, 30);

        bob.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 7 : Failed Sign ==========\n";
    try
    {
        Bureaucrat bob("Bob", 50);
        Form form("Contract", 20, 30);

        bob.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 8 : Grade 1 Bureaucrat ==========\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        Form form("Secret", 1, 1);

        boss.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 9 : Grade 150 Bureaucrat ==========\n";
    try
    {
        Bureaucrat intern("Intern", 150);
        Form form("Secret", 149, 149);

        intern.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 10 : Copy Constructor ==========\n";
    try
    {
        Form a("A", 20, 30);
        Form b(a);

        std::cout << "Original : " << a << std::endl;
        std::cout << "Copy     : " << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 11 : Assignment Operator ==========\n";
    try
    {
        Form a("A", 20, 30);
        Form b;

        b = a;

        std::cout << "A : " << a << std::endl;
        std::cout << "B : " << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 12 : Boundary Case ==========\n";
    try
    {
        Bureaucrat a("Boundary", 20);
        Form f("BoundaryForm", 20, 30);

        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
