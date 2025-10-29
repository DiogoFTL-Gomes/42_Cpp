#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Fulano_clap_name"), _name("Fulano"), ScavTrap(), FragTrap() {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name), ScavTrap(name), FragTrap(name) {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other){

}

DiamondTrap::~DiamondTrap(){

}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other){

}


void	DiamondTrap::attack(const std::string &target){
	if (this->_energy <= 0){
		std::cout << "\033[1;32mScavTrap " << this->_name << " has no energy to attack.\033[0m" << std::endl;
		return;
	}
	--this->_energy;
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){

}
