
#include "Fixed.hpp"

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	if (a > c)
// 		std::cout << "Yes indeed " << a << " is greater than " << c << std::endl;
// 	else if (c < a)
// 		std::cout << "Nope " << c << " is greater than " << a << std::endl;
// 	else
// 		std::cout << "en7alagli 3al na3em" << std::endl;

// 	Fixed	e;

// 	e = a * c;
// 	std::cout << "Result of arithmetic is " <<  a.operator+(c) << " and a is still " << a << std::endl;
// 	std::cout << "Result of arithmetic is " <<  e << " and a is still " << a << std::endl;

// 	return (0);
// }

int main( void )
{
	Fixed a;
	a = Fixed( 1234.4321f );
	Fixed const c( 42.42f );
	Fixed	e;

	// e = a.operator+(c);
	e = a + c;
	std::cout << "Result of arithmetic is " <<  e << " and a is still " << a << std::endl;

	Fixed	g;
	std::cout << "The result of x " << ++g << std::endl;
	std::cout << "The result of x " << g++ << std::endl;
	std::cout << "The result of x " << g << std::endl;

	Fixed::max(a , c);
	
	return (0);
}
