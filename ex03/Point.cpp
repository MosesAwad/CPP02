
#include "Point.hpp"

// Since, this->x and this->y are const, I wouldn't
// be able to do this:
// 	this->x = Fixed( 0 );
// 	this->y = Fixed ( 0 );
// I could bypass that requirement though in two ways:
// Way 1 (further explanation in the operator= overload
// function below):
// 	(Fixed) this->x = Fixed( 0 );
// 	(Fixed) this->y = Fixed ( 0 );
// Way 2:
// 	Initialize them in an initiliazer list as shown
// 	below, that works even with const attributes.
Point::Point( void ) : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const Point& other): x(other.x), y(other.y)
{
}

Point::Point(const float val1, const float val2) : x(Fixed(val1)), y(Fixed(val2))
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point& operand)
{
	// Here, I have to cast this->x and this->y as Fixed.
	// The reason is because, the Fixed x and y are variables
	// are declared as const in my Point class (due to subject
	// pdf requirements). The issue with that is that the = 
	// operator overloading in our Fixed class has a prototype
	// of:
	// Fixed& Fixed::operator=(const Fixed& operand) and since
	// the return type is not const, then I cannot have a 
	// const Fixed variable = something, it instead has to be
	// Fixed variable = something. So we cast it as Fixed to
	// sort of temporarily bypass the const requirement.
	if (this != &operand)
	{
		(Fixed) this->x = operand.x;
		(Fixed) this->y = operand.y;
	}
	return (*this);
}

// The const at the end here allows us to call
// .getXRaw() and .getYRaw() methods on const
// objects of the class Point as well. So now,
// I can call them in the bsp formula whose
// prototype has const Point a, const Point b,
// const Point c and const Point point. In a
// nutshell, By adding const after the parameter
// list of getXRaw and getYRaw, you indicate that
// these functions will not modify the state of
// the Point object they are called on. Consequently,
// they can be called on both const Point objects and 
// non-const Point objects.
int 	Point::getXRaw( void ) const
{
	return (x.getRawBits());	
}

int 	Point::getYRaw( void ) const
{
	return (y.getRawBits());	
}
