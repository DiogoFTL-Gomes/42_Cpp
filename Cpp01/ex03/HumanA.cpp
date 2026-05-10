#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_type) : _name( "\033[1;33m" + name + "\033[0m"), _theWeapon(weapon_type){
}

HumanA::~HumanA(){
}

std::string	HumanA::getHumanName() const{
	return (_name);
}

void	HumanA::attack() const{
	std::cout << this->getHumanName() << " attacks with their " << _theWeapon.getType() << std::endl;
}
