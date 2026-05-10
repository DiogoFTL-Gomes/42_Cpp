#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name( "\033[1;33m" + name + "\033[0m"), _theWeapon(NULL){
}

HumanB::HumanB(std::string name, Weapon &thisWeapon) : _name( "\033[1;33m" + name + "\033[0m"), _theWeapon(NULL){
	this->setWeapon(thisWeapon);
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
	if (this->_theWeapon == NULL)
		std::cout << this->getHumanName() << " has no weapon" << std::endl;
	else
		std::cout << this->getHumanName() << " attacks with their " << _theWeapon->getType() << std::endl;
}
