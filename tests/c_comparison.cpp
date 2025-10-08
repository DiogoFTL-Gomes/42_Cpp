#include <iostream>
#include "c_comparison.hpp"

C_comparison::C_comparison(int v, char x) : letter(x), _val(v)
{
	std::cout << "C_comparison constructer called" << std::endl;
	return ;
}

C_comparison::~C_comparison()
{
	std::cout << "C_comparison destructor called" << std::endl;
	return ;
}

int	C_comparison::getval(void) const
{
	return (this->_val);
}

int	C_comparison::compare(C_comparison * other) const
{
	std::cout << "Comparing " << this->letter << " with " << other->letter << std::endl;
	if (this->_val < other->getval())
	{
		std::cout << this->_val << " is smaller than " << other->_val << std::endl;
		return (-1);
	}
	else if (this->_val > other->getval())
	{
		std::cout << this->_val << " is larger than " << other->_val << std::endl;
		return (1);
	}
	std::cout << this->_val << " is the same as " << other->_val << std::endl;
	return (0);
}
