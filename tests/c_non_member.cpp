#include "c_non_member.hpp"
#include <iostream>

c_non_member::c_non_member(void)
{
	std::cout << "c_non_member constructer called" << std::endl;
	//this->_nbinst += 1;//Pode compilar e funcionar mas nao é correcto
	c_non_member::_nbinst += 1;
}

c_non_member::~c_non_member(void)
{
	std::cout << "c_non_member destructer called" << std::endl;
	c_non_member::_nbinst -= 1;
}

int	c_non_member::getnbrinst(void)
{
	return (c_non_member::_nbinst);
}

int	c_non_member::_nbinst = 0;//inicializa variavel declarada 
