#include <iostream>
#include "Fixed.hpp"

int	main(void){
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

	std::cout << "\n=== ARITHMETIC ===" << std::endl;
	Fixed x(5.05f);
	Fixed y(2);

	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;

	std::cout << "\n=== DIVISION BY ZERO ===" << std::endl;
	Fixed zero(0);
	std::cout << "x / 0 = " << (x / zero) << std::endl;

	std::cout << "\n=== COMPARISONS ===" << std::endl;
	std::cout << "x > y: " << (x > y) << std::endl;
	std::cout << "x < y: " << (x < y) << std::endl;
	std::cout << "x >= y: " << (x >= y) << std::endl;
	std::cout << "x <= y: " << (x <= y) << std::endl;
	std::cout << "x == y: " << (x == y) << std::endl;
	std::cout << "x != y: " << (x != y) << std::endl;

	std::cout << "\n=== INCREMENT/DECREMENT ===" << std::endl;
	Fixed z;
	std::cout << "z = " << z << std::endl;
	std::cout << "++z = " << ++z << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "z++ = " << z++ << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "--z = " << --z << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "z-- = " << z-- << std::endl;
	std::cout << "z = " << z << std::endl;

	std::cout << "\n=== MIN/MAX ===" << std::endl;
	Fixed a1(1.5f);
	Fixed a2(2.5f);
	const Fixed ca1(3.5f);
	const Fixed ca2(3.4f);

	std::cout << "min(a1, a2): " << Fixed::min(a1, a2) << std::endl;
	std::cout << "max(a1, a2): " << Fixed::max(a1, a2) << std::endl;
	std::cout << "min(ca1, ca2): " << Fixed::min(ca1, ca2) << std::endl;
	std::cout << "max(ca1, ca2): " << Fixed::max(ca1, ca2) << std::endl;

	return 0;
}


/*
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
	std::cout << a / 0 << std::endl;
	
	std::cout << "(a + 5.3f) * (b / 2) = " << (a + 5.3f) * ((Fixed)b / 2) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

return 0;
}*/