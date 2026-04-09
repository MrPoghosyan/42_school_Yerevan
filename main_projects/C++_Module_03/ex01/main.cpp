#include "ScavTrap.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    separator("BASIC CLAPTRAP");

    ClapTrap a("A");
    a.status();

    a.attack("target");
    a.takeDamage(5);
    a.beRepaired(3);
    a.status();

    a.takeDamage(100);     // kill
    a.attack("target");    // should fail
    a.beRepaired(5);       // should fail

    separator("SCAVTRAP CONSTRUCTION");

    ScavTrap b("B");
    b.status();

    separator("SCAVTRAP ACTIONS");

    b.attack("enemy");
    b.takeDamage(30);
    b.beRepaired(10);
    b.guardGate();
    b.status();

    separator("ENERGY EXHAUSTION");

    for (int i = 0; i < 60; i++)
        b.attack("dummy");

    b.status();

    separator("DEAD STATE TEST");

    b.takeDamage(200);   // kill ScavTrap
    b.attack("enemy");   // should fail
    b.beRepaired(10);    // should fail

    separator("COPY TEST (FRESH OBJECT)");

    ScavTrap fresh("Fresh");
    ScavTrap copy(fresh);

    copy.status();
    copy.attack("copy_target");   // should work
    copy.guardGate();

    separator("COPY TEST (EXHAUSTED OBJECT)");

    ScavTrap exhausted("Exhausted");
    for (int i = 0; i < 60; i++)
        exhausted.attack("dummy");

    ScavTrap copy2(exhausted);
    copy2.attack("target");   // should fail (copied state)

    separator("ASSIGNMENT TEST (FRESH)");

    ScavTrap d("D");
    d = fresh;

    d.status();
    d.attack("assigned_target"); // should work

    separator("ASSIGNMENT TEST (EXHAUSTED)");

    ScavTrap e("E");
    e = exhausted;

    e.attack("target"); // should fail

    separator("SELF ASSIGNMENT");

    ScavTrap* ptr = &d;
    d = *ptr;   // should not break anything
    d.attack("self_assign");

    std::cout << "\n=== POLYMORPHISM TEST ===\n";

    ClapTrap* poly = new ScavTrap("Poly");
    poly->attack("enemy");
    delete poly;

    separator("END (DESTRUCTION ORDER)");

    return 0;
}
