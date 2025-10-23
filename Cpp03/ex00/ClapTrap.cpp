#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "ClapTrap " << this->_name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack) {
	std::cout << "ClapTrap " << this->_name << " has been constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	if (this != &other){
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energy = other._energy;
		this->_hit = other._hit;
	}
	std::cout << "ClapTrap " <<this->_name << " has been constructed!" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	std::cout << "ClapTrap " << this->_name << " atacks " << target << " causing "<< this->_attack << " points of damage." << std::endl;}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " has taken" << amount << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " has recovered" << amount << " points of health" << std::endl;
}

//for testing 

std::string	ClapTrap::getName() const{
	return (this->_name);
}