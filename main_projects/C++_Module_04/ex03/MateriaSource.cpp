#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.storage[i])
			storage[i] = other.storage[i]->clone();
		else
			storage[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i){
			delete storage[i];
			storage[i] = NULL;
		}

		for (int i = 0; i < 4; ++i)
			if (other.storage[i])
				storage[i] = other.storage[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i){
		delete storage[i];
		storage[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (storage[i] == NULL){
			storage[i] = m->clone(); //Key line
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (storage[i] && storage[i]->getType() == type)
			return storage[i]->clone(); //factory
	}
	return 0;
}
