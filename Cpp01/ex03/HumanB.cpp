#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name( "\033[1;33m" + name + "\033[0m"){
}

HumanB::~HumanB(){
}

std::string	HumanB::getHumanName() const{
	return (_name);
}

void	HumanB::setWeapon(Weapon &thisWeapon){
	_theWeapon = &thisWeapon;
}

void	HumanB::attack() const{
	std::cout << this->getHumanName() << " attacks with their " << _theWeapon->getType() << std::endl;
}
