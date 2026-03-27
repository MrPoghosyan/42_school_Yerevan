#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
/*

int main()
{
    std::cout << "=== Constructors ===" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "\n=== Assignment ===" << std::endl;
    a = Fixed(5.5f);

    std::cout << "\n=== Output ===" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    std::cout << "\n=== Comparison ===" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "\n=== Arithmetic ===" << std::endl;
    Fixed x(5.05f);
    Fixed y(2);

    std::cout << "x + y: " << (x + y) << std::endl;
    std::cout << "x - y: " << (x - y) << std::endl;
    std::cout << "x * y: " << (x * y) << std::endl;
    std::cout << "x / y: " << (x / y) << std::endl;

    std::cout << "\n=== Increment / Decrement ===" << std::endl;
    Fixed inc(1);

    std::cout << "inc: " << inc << std::endl;
    std::cout << "++inc: " << ++inc << std::endl;
    std::cout << "inc: " << inc << std::endl;
    std::cout << "inc++: " << inc++ << std::endl;
    std::cout << "inc: " << inc << std::endl;

    std::cout << "--inc: " << --inc << std::endl;
    std::cout << "inc--: " << inc-- << std::endl;
    std::cout << "inc: " << inc << std::endl;

    std::cout << "\n=== Min / Max ===" << std::endl;
    Fixed m1(3);
    Fixed m2(7);

    std::cout << "min: " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max: " << Fixed::max(m1, m2) << std::endl;

    const Fixed cm1(1.5f);
    const Fixed cm2(2.5f);

    std::cout << "const min: " << Fixed::min(cm1, cm2) << std::endl;
    std::cout << "const max: " << Fixed::max(cm1, cm2) << std::endl;

    std::cout << "\n=== Conversion ===" << std::endl;
    std::cout << "c as float: " << c.toFloat() << std::endl;
    std::cout << "c as int: " << c.toInt() << std::endl;

    return 0;
}
*/
