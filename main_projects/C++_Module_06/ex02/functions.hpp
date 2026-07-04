#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include "ABC.hpp"

/*
** The mandatory cast for this exercise is dynamic_cast, used to inspect
** the real, most-derived type of a polymorphic object at runtime -
** without including <typeinfo>, as required by the subject.
*/
Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
