#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "ClapTrap " << _name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){}
ClapTrap &ClapTrap::operator=(const ClapTrap &other){}
ClapTrap::~ClapTrap(){}

void	ClapTrap::attack(const std::string& target){}
void	ClapTrap::takeDamage(unsigned int amount){}
void	ClapTrap::beRepaired(unsigned int amount){}
