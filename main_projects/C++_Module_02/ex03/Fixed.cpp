#include "Fixed.hpp"

float Fixed::toFloat( void ) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed( void )
	:_value(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n)
{
//	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
//	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fractionalBits));
}

Fixed& Fixed::operator=( const Fixed& other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;

	return *this;
}

Fixed::~Fixed( void )
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::min( Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max( Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}

/*****    Comparison operators    *****/
bool Fixed::operator>( const Fixed& other ) const
{
	return _value > other._value;
}

bool Fixed::operator<( const Fixed& other ) const
{
	return _value < other._value;
}

bool Fixed::operator>=( const Fixed& other ) const
{
	return _value >= other._value;
}

bool Fixed::operator<=( const Fixed& other ) const
{
	return _value <= other._value;
}

bool Fixed::operator==( const Fixed& other ) const
{
	return _value == other._value;
}

bool Fixed::operator!=( const Fixed& other ) const
{
	return _value != other._value;
}

/*****    Arithmetic operators    *****/
Fixed Fixed::operator+( const Fixed& other ) const
{
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-( const Fixed& other ) const
{
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*( const Fixed& other ) const
{
	Fixed result;
	result._value = (_value * other._value) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/( const Fixed& other ) const
{
	Fixed result;
	result._value = (_value << _fractionalBits) / other._value;
	return result;
}

/*****    Increment | Decrement    *****/
Fixed& Fixed::operator++( void )
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--( void )
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);
	_value -= 1;
	return temp;
}
