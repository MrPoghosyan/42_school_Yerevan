#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	int _value;
	static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed( const int n );
		Fixed( const float f );
		Fixed& operator=( const Fixed& other );
		~Fixed();

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&  operator<<( std::ostream& out, const Fixed& fixed );

#endif /* FIXED_HPP */
