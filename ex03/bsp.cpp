
#include "Point.hpp"

int	get_triangle_area(Point const vertex_1, Point const vertex_2, Point const vertex_3)
{
	int	area;

	area = (vertex_1.getXRaw() * (vertex_2.getYRaw() - vertex_3.getYRaw()))
			+ (vertex_2.getXRaw() * (vertex_3.getYRaw() - vertex_1.getYRaw()))
			+ (vertex_3.getXRaw() * (vertex_1.getYRaw() - vertex_2.getYRaw()));
	area = std::abs(area);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	sub_area1;
	int	sub_area2;
	int	sub_area3;
	int	area;

	sub_area1 = get_triangle_area(a, b, point);
	sub_area2 = get_triangle_area(a, c, point);
	sub_area3 = get_triangle_area(b, c, point);

	area = get_triangle_area(a, b, c);

	std::cout << "Big area " << area << "\n";
		std::cout << "area1 " << sub_area1 << "\n";
		std::cout << "area2 " << sub_area2 << "\n";
		std::cout << "area3 " << sub_area3 << "\n";
	std::cout << "Sum areas " << sub_area1 + sub_area2 + sub_area3 << "\n";
	if (sub_area1 == 0 || sub_area2 == 0 || sub_area3 == 0)
		return false;
	if (area >= sub_area1 + sub_area2 + sub_area3)
		return true;
	return false;
}
