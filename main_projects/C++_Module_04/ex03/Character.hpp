#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* inventory[4];

		static AMateria* dropped[100];
		static int _index;

	public:
		Character();
		Character(std::string const & name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		static void cleanupDropped(); // Idempotent
};

#endif /* CHARACTER_HPP */
