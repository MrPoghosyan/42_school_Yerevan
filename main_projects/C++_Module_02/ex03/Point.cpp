#include "Point.hpp"

Point::Point()
	: x(0),
	  y(0)
{
	// Default
}

Point::Point( const float& x, const float& y )
	: x(x), y(y)
{
	// Param constructor
}

Point::Point( const Point& other )\
		: x(other.x), y(other.y)
{
	// Copy constructor
}

// Assignment operator (! cannot assign const member)
Point& Point::operator=( const Point& other )
{
	(void)other;
	return *this;
}

Point::~Point(){}

Fixed Point::getX( void ) const
{
	return x;
}

Fixed Point::getY( void ) const
{
	return y;
}
