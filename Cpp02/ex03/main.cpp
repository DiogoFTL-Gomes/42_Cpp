#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void){
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(5.0f, 5.0f);
	Point	point(4.7, 3.06);
	if (bsp(a, b, c, point) == true)
		std::cout << "It's IN!!!" << std::endl;
	else
		std::cout << "It's out :(" << std::endl;
	return 0;
}
