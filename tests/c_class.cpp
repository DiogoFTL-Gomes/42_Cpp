#include <iostream>
#include "c_class.hpp"

Sample::Sample(void)
{
	std::cout << "OHMERGORD!! IT WERKED!" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "BYE BYE SAMPLE CLASS!!" << std::endl;
	return;
}
