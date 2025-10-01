#include <iostream>
#include "this.hpp"

Sample::Sample(void)
{
	std::cout << "OHMERGORD!! IT WERKED!" << std::endl;
	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;
	this->bar(this->foo);
	return;
}

Sample::~Sample(void)
{
	std::cout << "Sera que ainda pega nos valores aqui? " << this->foo - 10 << std::endl; 
	std::cout << "BYE BYE SAMPLE CLASS!!" << std::endl;
	return;
}

void	Sample::bar(int vel)
{
	std::cout << "CHAMEI O BARRR COM O THIS!!!!" << std::endl;
	std::cout << this->foo - vel << std::endl;
	return;
}