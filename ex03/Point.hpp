
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point( const Point& other );
		Point( const float val1, const float val2 );
		~Point();
		Point&	operator=( const Point& operand );
		int 	getXRaw( void ) const;
		int 	getYRaw( void ) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif