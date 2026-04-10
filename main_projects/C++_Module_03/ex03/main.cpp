#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== BASIC CONSTRUCTION =====" << std::endl;
    {
        DiamondTrap d("DI4M0ND");
    }

    std::cout << "\n===== FUNCTIONAL TEST =====" << std::endl;
    {
        DiamondTrap d("BattleBot");

        d.attack("enemy");      // MUST be ScavTrap attack
        d.takeDamage(20);
        d.beRepaired(10);

        d.guardGate();          // ScavTrap ability
        d.highFivesGuys();     // FragTrap ability

        d.whoAmI();             // name + clap_name
    }

    std::cout << "\n===== COPY CONSTRUCTOR TEST =====" << std::endl;
    {
        DiamondTrap d1("Original");
        DiamondTrap d2(d1);

        d2.whoAmI();
    }

    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
    {
        DiamondTrap d1("First");
        DiamondTrap d2("Second");

        d2 = d1;

        d2.whoAmI();
    }

    std::cout << "\n===== MULTIPLE OBJECTS TEST =====" << std::endl;
    {
        DiamondTrap a("A");
        DiamondTrap b("B");
        DiamondTrap c("C");

        a.attack("target");
        b.attack("target");
        c.attack("target");
    }

    std::cout << "\n===== ARRAY TEST =====" << std::endl;
    {
        DiamondTrap arr[2] = { DiamondTrap("One"), DiamondTrap("Two") };

        arr[0].whoAmI();
        arr[1].whoAmI();
    }

    std::cout << "\n===== ENERGY / HP EDGE CASES =====" << std::endl;
    {
        DiamondTrap d("Edge");

        // Kill the bot
        d.takeDamage(200);

        d.attack("enemy");      // should not work
        d.beRepaired(10);       // should not work

        d.whoAmI();             // still should work
    }

    std::cout << "\n===== SCOPE DESTRUCTION TEST =====" << std::endl;
    {
        DiamondTrap d("Scoped");
    } // destructor chain must be visible here

    std::cout << "\n===== END =====" << std::endl;
    return 0;
}
