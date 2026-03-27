#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	int					_value;
	static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed( const int n );
		Fixed( const float f );
		Fixed&	operator=( const Fixed& other );
		~Fixed();

	public: // Comparison operators
		bool	operator>( const Fixed& other ) const;
		bool	operator<( const Fixed& other ) const;
		bool	operator>=( const Fixed& other ) const;
		bool	operator<=( const Fixed& other ) const;
		bool	operator==( const Fixed& other ) const;
		bool	operator!=( const Fixed& other ) const;

	public: // Arithmetic operators
		Fixed operator+( const Fixed& other) const;
		Fixed operator-( const Fixed& other) const;
		Fixed operator*( const Fixed& other) const;
		Fixed operator/( const Fixed& other) const;

	public: // Increment | Decrement
		Fixed& operator++( void );
		Fixed operator++( int );
		Fixed& operator--( void );
		Fixed operator--( int );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed& max( Fixed& a, Fixed& b );
		static const Fixed& max( const Fixed& a, const Fixed& b );
		static Fixed& min( Fixed& a, Fixed& b );
		static const Fixed& min( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<( std::ostream &out, const Fixed &fixed );

#endif /* FIXED_HPP */
