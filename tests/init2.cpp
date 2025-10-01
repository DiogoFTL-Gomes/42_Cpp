#include <iostream>
#include "init2.hpp"

init2::init2(char p1, int p2, float p3) : b1(p1), b2(p2), b3(p3)
{
	std::cout << "Chamando constructor init2" << std::endl;

	std::cout << "this->b1 = " << this->b1 << std::endl;
	std::cout << "this->b2 = " << this->b2 << std::endl;
	std::cout << "this->b3 = " << this->b3 << std::endl;
	return;
}

init2::~init2(void)
{
	std::cout << "Destruindo init2";
	std::cout << " b1 = " << this->b1 << std::endl;
	return;
}
