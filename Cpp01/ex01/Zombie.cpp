#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){
}

Zombie::Zombie(std::string name) : _name(name) {
	this->announce();
}

Zombie::~Zombie(void){
	std::cout << "Shooting " << this->_name << " in the head..." << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	this->_name = name;
	this->announce();
}
