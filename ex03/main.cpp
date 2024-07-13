
#include "Point.hpp"

int main()
{
	Point a(6.5, 10.8);
	Point b(2, 2);
	Point c(10.23, 2);

	Point point(6.5, 10.5);
	if (bsp(a, b, c, point))
		std::cout << "Congrats, you are in the triangle\n";
	else
		std::cout << "Sorry mate, you aren't in the triangle\n";
}
