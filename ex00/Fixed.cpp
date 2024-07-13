
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

// Technically, you can also do this->value = operand.value
// but in the subject pdf, right after doing b( a ), we see
// that the output log says "Copy assignment operator called"
// and then right after it "getRawBits member function called"
// even though the next line is c = b and not a.getRawBits().
// So I know that they are using getRawBits() to obtain the
// value.
//
// Also the reason why this->value = operand.value works, even
// though value is a private attribute because Fixed( const Fixed& other)
// is also a member function, so it can access private members
// of other objects of the SAME CLASS.
//
// SAME NOTES APPLY TO Fixed& Fixed::operator=(const Fixed& operand)
Fixed::Fixed( const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& operand)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &operand)
	{
		this->value = operand.getRawBits();
	}
	return (*this);
}
/*
	The const keyword at the end of a function here just means
	that the member function promises not to modify any member
	variables of the object on which it is called. Putting const
	at the end of a function prototype is only applicable for class
	member functions, that's it. A normal function cannot have the
	const keyword at the end of it. As for the function  below though,
	called setRawBits alters the value member of the Fixed class object
	on which it is called,=; and hence, why it does not have the const 
	keyword at the end of it.
*/
int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
