#include "Fixed.hpp"
#include "Point.hpp"

Fixed	tArea(Point const a, Point const b, Point const c){
	Fixed	temp;

	temp = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	if (temp < 0)
		temp = temp * (-1);
	std::cout << "temp area is " << temp / 2 << std::endl;
	return (temp / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed 	triangle = tArea(a, b, c);
	Fixed	pab = tArea(point, a, b);
	Fixed	pbc = tArea(point, b, c);
	Fixed	pca = tArea(point, c, a);

	if (pab.toFloat() == 0.0 || pbc.toFloat() == 0.0 || pca.toFloat() == 0.0)
		return (false);
	Fixed	pabc = pab + pbc + pca;
	std::cout << "sum of Pabc areas is " << pabc << std::endl;
	if (triangle - pabc > Fixed(0.01f))
		return (false);
	if (triangle - pabc < Fixed(-0.01f))
		return (false);
	return (true);
}
