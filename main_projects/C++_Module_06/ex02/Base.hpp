#ifndef BASE_HPP
# define BASE_HPP

/*
** Base only needs a public virtual destructor: the virtual table it
** introduces is what makes dynamic_cast (RTTI) usable on this hierarchy.
** Per the subject, Base/A/B/C do not need the Orthodox Canonical Form.
*/
class Base
{
	public:
		virtual ~Base();
};

#endif
