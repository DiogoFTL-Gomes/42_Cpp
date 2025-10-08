#include <iostream>
#include "c_pointers.hpp"

c_pointers::c_pointers(void) : foo(0)
{
	std::cout << "c_pointers contructor called" << std::endl;
	return ;
}

c_pointers::~c_pointers(void)
{
	std::cout << "c_pointers destructor called" << std::endl;
	return ;
}

void	c_pointers::bar(void) const
{
	std::cout << "c_pointers bar() called" << std::endl;
	return ;
}
