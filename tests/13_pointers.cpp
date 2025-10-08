#include <iostream>
#include "c_pointers.hpp"

int	main(void)
{
	c_pointers	example;
	c_pointers	*p_example = &example;

	int			c_pointers::*p = NULL;
	void		(c_pointers::*f)(void) const;

	p = &c_pointers::foo;
	std::cout << "Value of member foo: " << example.foo << std::endl;
	example.*p = 21;
	std::cout << "Value of member foo: " << example.foo << std::endl;
	p_example->*p = 42;
	std::cout << "Value of member foo: " << example.foo << std::endl;

	f = &c_pointers::bar;

	(example.*f)();
	(p_example->*f)();

	return (0);
}
