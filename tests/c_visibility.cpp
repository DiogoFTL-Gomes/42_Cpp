#include <iostream>
#include "c_visibility.hpp"

C_visibility::C_visibility(void){

	this->publicint = 0;
	std::cout << "this->publicint = " << this->publicint << std::endl;
	this->_privateint = 0;
	std::cout << "this->_privateint = " << this->_privateint << std::endl;

	this->publicft();
	this->_privateft();

	std::cout << "C_visibility constructed" << std::endl;

	return ;
}

C_visibility::~C_visibility(void){

	std::cout << "C_visibility destroyed" << std::endl;
	return ;
}

void	C_visibility::publicft(void) const{

	std::cout << "Member function publicft() called" << std::endl;
	return ;
}

void	C_visibility::_privateft(void) const {

	std::cout << "Member function _privateft() called" << std::endl;
	return ;
}