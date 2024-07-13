
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
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int 	toInt( void ) const;
		float 	toFloat( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif