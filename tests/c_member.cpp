#include <iostream>
#include "c_member.hpp"

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

void	Sample::bar(void)
{
	std::cout << "CHAMEI O BARRR!!" << std::endl;
	return;
}