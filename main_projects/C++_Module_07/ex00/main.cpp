#include <iostream>
#include <string>
#include "whatever.hpp"

int	main(void)
{
	int			a;
	int			b;
	std::string	c;
	std::string	d;

	a = 2;
	b = 3;
	c = "chaine1";
	d = "chaine2";
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return (0);
}
