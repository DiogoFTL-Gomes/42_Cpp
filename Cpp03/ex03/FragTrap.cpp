#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "\033[1;33mFragTrap " << this->_name << " constructed itself from nothing!\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "\033[1;33mA FragTrap has been named " << this->_name << " and was constructed!\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	this->_hit = other._hit;
	this->_energy = other._energy;
	this->_attack = other._attack;
	std::cout << "\033[1;33mFrom another FragTrap, " << this->_name << " has been constructed!\033[0m" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
		std::cout << "\033[1;33mFragTrap " << this->_name << " has been equalized to other\033[0m" << std::endl;
	}
	else{
		std::cout << "\033[1;33mFragTrap " << this->_name << " cannot be equalized to itself\033[0m" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "\033[1;33mFragTrap " << this->_name << " burns away from memory!\033[0m" << std::endl;
}

void	FragTrap::highFivesGuys(){
	std::cout << "\033[1;33mFragTrap " << this->_name << " high fives everybody \"Whats up, bros?!?!\"\033[0m" << std::endl;
}
