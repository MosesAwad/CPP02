
#include "Point.hpp"

int main()
{
	Point a(6.5, 10.8);
	Point b(-8, 2);
	Point c(10.23, 2);

	Point point(6.5, 10.5);
	if (bsp(a, b, c, point))
		std::cout << "Congrats, you are in the triangle\n";
	else
		std::cout << "Sorry mate, you aren't in the triangle\n";

	Point point2(6.5, 10.8);
	if (bsp(a, b, c, point2))
		std::cout << "Congrats, you are in the triangle\n";
	else
		std::cout << "Sorry mate, you aren't in the triangle\n";

	Point point3(5.5, 5.5);
	if (bsp(a, b, c, point3))
		std::cout << "Congrats, you are in the triangle\n";
	else
		std::cout << "Sorry mate, you aren't in the triangle\n";
	
	Point point4(-1, 4);
	if (bsp(a, b, c, point4))
		std::cout << "Congrats, you are in the triangle\n";
	else
		std::cout << "Sorry mate, you aren't in the triangle\n";

	Point point5(-1, 7);
	if (bsp(a, b, c, point5))
		std::cout << "Congrats, you are in the triangle\n";
	else
		std::cout << "Sorry mate, you aren't in the triangle\n";

}
