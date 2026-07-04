#ifndef DATA_HPP
# define DATA_HPP

# include <string>

/*
** Non-empty structure used to prove that serialize()/deserialize()
** round-trip a pointer correctly (the members themselves are not used
** by the serialization logic, they only make the struct "non-empty").
*/
struct Data
{
	int			id;
	std::string	label;
	double		value;
};

#endif
