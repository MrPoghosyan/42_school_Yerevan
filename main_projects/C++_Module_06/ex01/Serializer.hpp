#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

/*
** Serializer
** ----------
** Purely static utility class: not initializable in any way, so every
** special member function is private and unimplemented.
**
** The mandatory cast for this exercise is reinterpret_cast, since we are
** reinterpreting the bit pattern of a pointer as an unrelated integer
** type (uintptr_t) and back, which is exactly what reinterpret_cast is
** meant for.
*/
class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();
};

#endif
