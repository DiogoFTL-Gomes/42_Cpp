#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "ClapTrap " << this->_name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack) {
	std::cout << "ClapTrap " << this->_name << " has been constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap " << this->_name << " is now equal to " << other._name << std::endl;
	if (this != &other){
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energy = other._energy;
		this->_hit = other._hit;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (this->_energy <= 0){
		std::cout << "ClapTrap " << this->_name << " has no energy to attack." << std::endl;
		return;
	}
	--this->_energy;
	std::cout << "ClapTrap " << this->_name << " atacks " << target << " causing "<< this->_attack << " points of damage." << std::endl;}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_hit -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy <= 0){
		std::cout << "ClapTrap " << this->_name << " has no energy to do repairs." << std::endl;
		return;
	}
	--this->_energy;
	this->_hit += amount;
	std::cout << "ClapTrap " << this->_name << " has recovered " << amount << " points of health" << std::endl;
}

//for testing 

std::string	ClapTrap::getName() const{
	return (this->_name);
}