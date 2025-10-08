#include <iostream>
#include "c_get_set.hpp"

get_set::get_set(void)
{
	std::cout << "get_set constructor called" << std::endl;

	this->setval(0);
	std::cout << "Val inicial: " << this->getval() << std::endl;

	return ;
}

get_set::~get_set(void)
{
	std::cout << "get_set destroyed" << std::endl;
	return ;
}

int		get_set::getval(void) const
{
	return this->_val;
}

void	get_set::setval(int v)
{
	if (v >= 0)
		this->_val = v;
	else
		std::cout << " Value is below zero" << std::endl;
}