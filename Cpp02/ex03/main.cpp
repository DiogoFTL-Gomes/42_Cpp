#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void){
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(5.0f, 5.0f);
	Point	point(3.05f, 3.0f);
	std::cout << "Point ax:" << a.getX() << " ay: " << a.getY() << std::endl;
	std::cout << "Point bx:" << b.getX() << " by: " << b.getY() << std::endl;
	std::cout << "Point cx:" << c.getX() << " cy: " << c.getY() << std::endl;
	std::cout << "Point x:" << point.getX() << " y: " << point.getY() << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "It's IN!!!" << std::endl;
	else
		std::cout << "It's out :(" << std::endl;
	return 0;
}
