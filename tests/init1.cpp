#include <iostream>
#include "init1.hpp"

init1::init1(char p1, int p2, float p3)
{
	std::cout << "Chamando constructor init1" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	this->a2 = p2;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	this->a3 = p3;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	return;
}

init1::~init1(void)
{
	std::cout << "Destruindo init1";
	std::cout << " a1 = " << this->a1 << std::endl;
	return;
}
