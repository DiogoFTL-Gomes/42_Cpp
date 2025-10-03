#include <iostream>
#include "c_const.hpp"

C_const::C_const(float const f) : pi(f), qf(42)
{
	std::cout << "C_const constructer called" << std::endl;
	return;
}

C_const::~C_const(void)
{
	std::cout << "C_const destructor called" << std::endl;
	return;
}

void	C_const::bar(void) const
{
	std::cout << "this->pi: " << this->pi << std::endl;
	std::cout << "this->qf: " << this->qf << std::endl;

	//metodo const nao pode mudar nada na classe
	//so posivel se declarar qf como mutable na classe
	//this->qf = 0; //isto nao permite compilação

	return;
}
