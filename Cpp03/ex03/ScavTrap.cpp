#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(){
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "\033[1;32mScavTrap " << this->_name << " has been constructed!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "\033[1;32mScavTrap " << this->_name << " has been constructed!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	this->_hitPoints = other._hitPoints;
	this->_energy = other._energy;
	this->_attack = other._attack;
	std::cout << "\033[1;32mScavTrap " << this->_name << " has been constructed!\033[0m" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
		this->_hitPoints = other._hitPoints;
		this->_energy = other._energy;
		this->_attack = other._attack;
		std::cout << "\033[1;32mScavTrap " << this->_name << " has been equalized to other\033[0m" << std::endl;
	}
	else{
		std::cout << "\033[1;32mScavTrap " << this->_name << " cannot be equalized to itself\033[0m" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "\033[1;32mScavTrap " << this->_name << " has been destroyed!\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_energy <= 0){
		std::cout << "\033[1;32mScavTrap " << this->_name << " has no energy to attack.\033[0m" << std::endl;
		return;
	}
	--this->_energy;
	std::cout << "\033[1;32mScavTrap " << this->_name << " deals " << target << " a mighty blow of "<< this->_attack << " points of damage.\033[0m" << std::endl;
}


void	ScavTrap::guardGate(){
	std::cout << "\033[1;32mScavTrap " << this->_name << " is guarding the gates. \"Come at me, bro!!!\"\033[0m" << std::endl;
}
