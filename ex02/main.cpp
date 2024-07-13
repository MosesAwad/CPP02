
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

	std::cout << "\n ---- 4 aithmetic operators test ---- " << std::endl;
	// e = a.operator+(c);
	e = a + c;
	std::cout << "Result of + arithmetic is " <<  e << " and a is still " << a << std::endl;
	e = a - c;
	std::cout << "Result of - arithmetic is " <<  e << " and a is still " << a << std::endl;
	e = a * c;
	std::cout << "Result of * arithmetic is " <<  e << " and a is still " << a << std::endl;
	e = a / c;
	std::cout << "Result of / arithmetic is " <<  e << " and a is still " << a << std::endl;

	std::cout << "\n ---- 4 increment/decrement operators test ---- " << std::endl;
	Fixed	g(5);
	std::cout << "The result of g " << ++g << std::endl;
	std::cout << "The result of g " << g++ << std::endl;
	std::cout << "The result of g " << g << std::endl;
	
	std::cout << "The result of g " << --g << std::endl;
	std::cout << "The result of g " << g-- << std::endl;
	std::cout << "The result of g " << g << std::endl;

	std::cout << "\n ---- 4 overloaded min, max functions test ---- " << std::endl;
	std::cout << "The greater of a and c is " << Fixed::max(a , c) << std::endl;
	std::cout << "The lesser of a and c is " << Fixed::min(a , c) << std::endl;

	const Fixed x( 1234.4321f );
	const Fixed y( 42.42f );
	std::cout << "The greater of x and y is " << Fixed::max(x , y) << std::endl;
	std::cout << "The lesser of x and y is " << Fixed::min(x , y) << std::endl;

	std::cout << "\n ---- 6 comparison operators test ---- " << std::endl;
	if (a != c)
		std::cout << "!= operator working correctly " << std::endl;

	Fixed f(5);
	Fixed h(5);
	if (f == h)
		std::cout << "== operator working correctly " << std::endl;
	if (f >= h)
		std::cout << "Test 1: >= operator working correctly " << std::endl;	
	if (g >= h)
		std::cout << "Test 2: >= operator working correctly " << std::endl;
	if (f <= h)
		std::cout << "Test 1: <= operator working correctly " << std::endl;	
	if (h <= g)
		std::cout << "Test 2: <= operator working correctly " << std::endl;	
	if (g > h)
		std::cout << "> operator working correctly " << std::endl;
	if (h < g)
		std::cout << "< operator working correctly " << std::endl;

	return (0);
}
