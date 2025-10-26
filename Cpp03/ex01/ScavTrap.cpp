#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(){
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m has been constructed!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m has been constructed!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	this->_hitPoints = other._hitPoints;
	this->_energy = other._energy;
	this->_attack = other._attack;
	std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m has been constructed!\033[0m" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m has been equalized to other\033[0m" << std::endl;
	}
	else{
		std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m cannot be equalized to itself\033[0m" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m has been destroyed!\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_energy <= 0){
		std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32 has no energy to attack.\033[0m" << std::endl;
		return;
	}
	--this->_energy;
	std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m attacks " << target << "\033[1;32m causing "<< this->_attack << "\033[1;32m points of damage.\033[0m" << std::endl;
}


void	ScavTrap::guardGate(){
	std::cout << "\033[1;32mScavTrap " << this->_name << "\033[1;32m is guarding the gates. \"Come at me, bro!!!\"\033[0m" << std::endl;
}
