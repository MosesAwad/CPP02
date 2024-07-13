
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include  <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed();
		Fixed&	operator=(const Fixed& operand);
		bool	operator<(const Fixed& operand) const;
		bool	operator>(const Fixed& operand) const;
		bool	operator<=(const Fixed& operand) const;
		bool	operator>=(const Fixed& operand) const;
		bool	operator==(const Fixed& operand) const;
		bool	operator!=(const Fixed& operand) const;
		Fixed	operator+(const Fixed& operand);
		Fixed	operator-(const Fixed& operand);
		Fixed	operator*(const Fixed& operand);
		Fixed	operator/(const Fixed& operand);
		Fixed& 	operator++(void);
		Fixed	operator++(int);
		Fixed& 	operator--(void);
		Fixed 	operator--(int);
		static Fixed&		min(Fixed& fix1, Fixed& fix2);
		static const Fixed&	min(const Fixed& fix1, const Fixed& fix2);
		static Fixed&		max(Fixed& fix1, Fixed& fix2);
		static const Fixed&	max(const Fixed& fix1, const Fixed& fix2);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int 	toInt( void ) const;
		float 	toFloat( void ) const;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i );

#endif