
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

Fixed::Fixed( const int value )
{
	this->value = value << this->bits;	// left shifting is equivalent to * 2^8
}
/*
	We cannot directly do value << this->bits here cuz value is
	a float. So what we do instead is value * (1 << this->bits).
	The reason is because doing bitshifting on a float value results
	in a compilation error. So instead, we just say value * (1 << this->bits)
	which is exactly the same as value * 256. So technically, we're not
	bitshifting the actual  value like in Fixed::Fixed( const int value ),
	we are just bitshifting the 1 by 8 bits to the left to get the equivalent
	of value * 256. And then that result, we just round it using roundf to
	get a more accurate value. So if the result is 3763.2, the result is
	store as 3764 in the value member cuz value is an int. And if it was 
	3763.8, it would be stored as 3765. That's it!
*/
Fixed::Fixed( const float value )
{
	this->value = roundf(value * (1 << this->bits));
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

int 	Fixed::toInt( void ) const
{
	int	result;

	result = this->value >> this->bits;	// this is the equivalent of (/ 2^8).
	return (result);
}

/*
	You must cast this->value as a float because in our class, this->value 
	and this->bits are both ints. So, even if result is a float, it would
	have done integer division and gave us an integer result.
*/
float 	Fixed::toFloat( void ) const
{
	float	result;

	result = static_cast<float>(this->value) / (1 << this->bits);
	return (result);
}

std::ostream& operator<<( std::ostream& o, const Fixed& i )
{
    o << i.toFloat();
    return (o);
}
