#include "member.hpp"
#include <iostream>

int	main(void)
{
	Sample	testing;

	testing.foo = 42;
	std::cout << "testing.foo: " << testing.foo << std::endl;
	testing.bar();
	return (0);
}