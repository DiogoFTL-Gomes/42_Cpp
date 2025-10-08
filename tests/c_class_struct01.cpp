#include <iostream>
#include "c_class_struct01.hpp"

C_class_struct01::C_class_struct01(void)
{
	std::cout << "constructed struct" << std::endl;
	return;
}

C_class_struct01::~C_class_struct01(void)
{
	std::cout << "BYE BYE SAMPLE struct!!" << std::endl;
	return;
}

void	C_class_struct01::ft_example(void) const
{
	std::cout << "CHAMEI O BARRR da struct!!" << std::endl;
	return;
}
