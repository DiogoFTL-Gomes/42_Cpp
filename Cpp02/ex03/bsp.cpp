#include "Fixed.hpp"
#include "Point.hpp"

Fixed	tArea(Point const a, Point const b, Point const c){
	Fixed	temp;

	temp = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	if (temp < 0)
		temp = temp * (-1);
	return (temp / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed 	triangle = tArea(a, b, c);
	Fixed	pab = tArea(point, a, b);
	Fixed	pbc = tArea(point, b, c);
	Fixed	pca = tArea(point, c, a);

	if (pab == 0.0f || pbc == 0.0f || pca == 0.0f)
		return (false);
	Fixed	pabc = pab + pbc + pca;
	if (triangle - pabc > Fixed(0.01f))
		return (false);
	if (triangle - pabc < Fixed(-0.01f))
		return (false);
	return (true);
}
