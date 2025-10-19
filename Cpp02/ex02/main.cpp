#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b =" << a + b << std::endl;
	std::cout << "a - b =" << a - b << std::endl;
	std::cout << "a * b =" << a * b << std::endl;
	std::cout << "a / b =" << a / b << std::endl;
	std::cout << "a + 5 =" << a + 5 << std::endl;
	std::cout << "a + 2.6f =" << a + 2.6f << std::endl;
	std::cout << a << "<- a | ++a ->" << ++a << std::endl;
	std::cout << a++ << "<- a++ | a ->" << a << std::endl;
	std::cout << a * 2 << "|" << a * 3 << "|" << a * 4 << std::endl;
	
	std::cout << "(a * 5) * (b / 2) = " << (a * 5) * ((Fixed)b / 2) << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;

return 0;
}