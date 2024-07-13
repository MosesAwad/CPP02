
#include "Fixed.hpp"

// SECTION 1 -- CONSTRUCTORS
Fixed::Fixed(void)
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
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->bits;
}

// We cannot directly do value << this->bits here
// cuz value is a float. So what we do instead is
// value * (1 << this->bits)
Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << this->bits));
}

// SECTION 2 -- DESTRUCTOR
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// SECTION 3 -- COMPARISON OPERATORS OVERLOAD
// 
// Yes we are returning a reference to a an object of class Fixed.
// The object I want to send back is 'this', not 'operand'. That's
// why I return (*this). Now why do I return (*this) and not
// return (this), even though I am returning a reference and not
// a pointer? Well, first, if you go for the latter option, you
// will get the following error:
// initial value of reference to non-const must be an lvalue
// And lvalue is an expression that refers to a memory location.
// Well, you see, when you work with this, this is automatically
// set as a pointer by C++. You didn't set it up as a pointer, but
// it is! It functions as a pointer to your class. That is why when
// you want access one of its members, you do this->value. Just like
// for example, in So_Long, you have a function with (t_game *game)
// and you want to access a member like coin_count, you type in
// game->coin_count. So in this function, I am returning a refernce
// to the class Fixed and not a pointer (otherwise my prototype would
//  have had to be:
// Fixed* Fixed::operator=(const Fixed& operand) akin to CPP01's
// Zombie	*newZombie( std::string name)). As a result, if I want
// to return a reference, which is just an alias for an existing
// variable, I need to derefence the this pointer and send back
// *this. And just for extra knowledge, "this" is just a keyword
// to refer to the object for which the member function is called.
// So if I do something like a = b, then what happens is that 'a' is
// calling the operator= overload member function and since I want
// to return 'a' itself and not another variable that is a copy of
// 'a', I am returning a reference to 'a'.
// As for why the argument of the function is also passed by reference
// even though I am not changing AND I CANNOT (cuz it's const) change
// anything with it, well the answer is simply due to efficiency.
// When you pass an object by value (as opposed to by reference), 
// a copy of the object is created. This involves calling the copy
// constructor, which can be expensive if the object has a lot of data
//  or if the copy constructor is complex. As such, when you pass by
// reference, you pass a reference (essentially a pointer under the
// hood) to the existing object. This avoids the overhead of copying
//  the object.
Fixed& Fixed::operator=(const Fixed& operand)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &operand)
	{
		this->value = operand.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator<(const Fixed& operand) const
{
	if (this->value < operand.value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& operand) const
{
	if (this->value > operand.value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& operand) const
{
	if (this->value <= operand.value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& operand) const
{
	if (this->value >= operand.value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& operand) const
{
	if (this->value == operand.value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& operand) const
{
	if (this->value != operand.value)
		return (true);
	return (false);
}

// SECTION 4 -- ARITHMETIC OPERATORS OVERLOAD
Fixed	Fixed::operator+(const Fixed& operand)
{
	Fixed	result;

	result.value = this->value + operand.value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& operand)
{
	Fixed	result;

	result.value = this->value - operand.value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &operand)
{
	Fixed 	result;
	int64_t	temp;
	// If we do something like Fixed a(1234.43f) and c(42.42f),
	// then Fixed.value of a would be 1234.43 * 256 (2^8) and
	// Fixed.value of c would be 42.42 * 256. So, if we do 
	// [(1234.43 * 256) * (42.42 * 256)] then this would defintely
	// overflow beyond the int range. So, to handle that issue,
	// we temporarliy store the result of (1234.43 * 256) * (42.42 * 256)]
	// in an int64_t which is the same as long long. We have to cast at
	// least one of the operands in there as <int64_t> otherwise, the 
	// compiler would just do standard integer division and not store
	// the value correctly even though temp is of type int64_t.
	temp = (static_cast<int64_t>(this->value) * (operand.value));
	// Anyways once we have the result stored in temp, we save that
	// result in value. But, we have to divide again by 256 because
	// the value is scaled up by a factor of 256^2 (because there
	// are 2 instance of 256 in [(1234.43 * 256) * (42.42 * 256)]!
	// and value needs to be scaled up by 256 only once! So, we scale
	// it back down to a factor of just 256 as opposed to 256^2 through
	// dividing it by 256.
	result.value = static_cast<int>(temp >> this->bits);
	return result;
}


Fixed Fixed::operator/(const Fixed &operand)
{
	Fixed	result;
	int64_t	temp;

	// Here I need to scale up the numerator for a different reason. It's kinda
	// weird but hopefully, this explanation would make it easy to understand.
	// Division actually doesn't need adjustment. So let's take the decimal 
	// (not binary equivalent). If we do 8.7 / 2.3 we get 3.78. If we scale up
	// by a factor of 100, then 870 / 230 still gives 3.78. The issue though is
	// that now, I am storing the actual value (not the scaled up value) in 
	// result.value. So if we convert this raw value back to float or to int 
	// (to get its float or int value, not the raw fixed point value), I would
	// end up left shifting by 8 bits (same as dividing by 256) on the raw value
	// even the raw value is the actual result! So to counteract that, I multiply
	// the temp result by 256 (hence multipling the numerator by 256) in order to
	// get the scaled raw value and not the real value of the division. Now, when
	// toFloat() or toInt() scale it back down, it will get the real value of the
	// division. 
	temp = (static_cast<int64_t>(this->value) << bits) / static_cast<int64_t>(operand.value);
	result.value = static_cast<int>(temp);
	return result;
}

// SECTION 5 -- INCREMENT AND DECREMENT OPERATORS
// This function handles PRE_INCREMENT ADDITION
Fixed& 	Fixed::operator++(void)
{
	++(this->value);
	return (*this);
}

// To best explain why we do this, try doing:
// 	int x = 5;
// 	std::cout << "The result of x " << x++ << std::endl;
// 	std::cout << "The result of x " << x << std::endl;
// First line would print an 5 while second line would
// print a 6.
// On the other hand:
// 	std::cout << "The result of x " << ++x << std::endl;
// 	std::cout << "The result of x " << x << std::endl;
// Would print a 6 for both lines.
Fixed 	Fixed::operator++(int)
{
	Fixed	result;

	result.value = this->value++;
	return (result);
}

Fixed& 	Fixed::operator--(void)
{
	--(this->value);
	return (*this);
}

Fixed 	Fixed::operator--(int)
{
	Fixed	result;

	result.value = this->value--;
	return (result);
}

// SECTION 6 -- INSERTION OPERATOR OVERLOAD
std::ostream& operator<<(std::ostream& o, const Fixed& i)
{
    o << i.toFloat();
    return o;
}

// SECTION 7 -- GETTERS AND SETTERS
int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// SECTION 8 -- CONVERTERS
int 	Fixed::toInt(void) const
{
	int	result;

	result = this->value >> this->bits;
	return (result);
}

// You must cast this->value as a float because
// in our class, this->value and this->bits are
// both ints. So, even if result is a float, it
// would have done integer division and gave us
// an integer result.
float 	Fixed::toFloat(void) const
{
	float	result;

	result = static_cast<float>(this->value) / (1 << this->bits);
	return (result);
}

// SECTION 9 - MIN, MAX FUNCTIONS OVERLOADING
//
// These functions are declared as static in our class
// defintion. What makes these functions special is that
// now, we can call them without having to use an object
// directly on the function (like with methods). So, what
// that means is as follows: to find the minimum of two
// objects for the Fixed class, I wouldn't need to do
// a.min(a, c) or even e.min(a, c), I can directly do
// Fixed::min(a, c) which makes more sense anyways. Because
// the passing of the objects a or e in a.min(a, c) and
// e.min(a, c) is basically useless, because what actually
// matters is just the parameters passed to the min function,
// the inner a object and the c object.
Fixed&	Fixed::min(Fixed& fix1, Fixed& fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

const Fixed&	Fixed::min(const Fixed& fix1, const Fixed& fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed&	Fixed::max(Fixed& fix1, Fixed& fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

const Fixed&	Fixed::max(const Fixed& fix1, const Fixed& fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}
