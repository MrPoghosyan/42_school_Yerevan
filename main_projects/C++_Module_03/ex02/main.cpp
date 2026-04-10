#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "===== BASIC CONSTRUCTION =====" << std::endl;

    {
        FragTrap f1("FR4G");
    } // ← այստեղ destruction-ը տեղի կունենա

    std::cout << "\n===== MULTIPLE OBJECTS =====" << std::endl;

    {
        ClapTrap c("CL4P");
        ScavTrap s("SC4V");
        FragTrap f("FR4G");
    } // ← այստեղ կտեսնես destruction order

    std::cout << "\n===== COPY TEST =====" << std::endl;

    {
        FragTrap f1("Original");
        FragTrap f2(f1);
    }

    std::cout << "\n===== ACTION TEST =====" << std::endl;

    {
        FragTrap f("ActionBot");

        f.attack("enemy");
        f.takeDamage(30);
        f.beRepaired(10);
        f.highFivesGuys();
    }

    std::cout << "\n===== ARRAY TEST =====" << std::endl;

    {
        FragTrap arr[2] = { FragTrap("One"), FragTrap("Two") };
    }

    std::cout << "\n===== END OF PROGRAM =====" << std::endl;
    return 0;
}
