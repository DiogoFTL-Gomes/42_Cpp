#include <iostream>
#include "c_class_struct02.hpp"

C_class_struct02::C_class_struct02(void)
{
	std::cout << "constructed class" << std::endl;
	return;
}

C_class_struct02::~C_class_struct02(void)
{
	std::cout << "BYE BYE SAMPLE CLASS!!" << std::endl;
	return;
}

void	C_class_struct02::ft_example(void) const
{
	std::cout << "CHAMEI O BARRR da class!!" << std::endl;
	return;
}
