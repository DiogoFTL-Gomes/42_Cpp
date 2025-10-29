#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Fulano_clap_name"), _name("Fulano") {
	this->_hit = FragTrap::sci_hit;
	this->_energy = ScavTrap::sci_energy;
	this->_attack = FragTrap::sci_attack;
	std::cout << "\033[1;34mNameless DiamondTrap " << this->_name << " has been constructed!\033[0m" << std::endl;
	std::cout << "\033[1;34mHit points \033[0m" << this->_hit << std::endl;
	std::cout << "\033[1;34mEnergy energy \033[0m" << this->_energy << std::endl;
	std::cout << "\033[1;34mAttack points \033[0m" << this->_attack << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) {
	this->_hit = FragTrap::sci_hit;
	this->_energy = ScavTrap::sci_energy;
	this->_attack = FragTrap::sci_attack;
	std::cout << "\033[1;34mDiamondTrap " << this->_name << " has been constructed!\033[0m" << std::endl;
	std::cout << "\033[1;34mHit points \033[0m" << this->_hit << std::endl;
	std::cout << "\033[1;34mEnergy energy \033[0m" << this->_energy << std::endl;
	std::cout << "\033[1;34mAttack points \033[0m" << this->_attack << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	this->_hit = FragTrap::sci_hit;
	this->_energy = ScavTrap::sci_energy;
	this->_attack = FragTrap::sci_attack;
	std::cout << "\033[1;34mDiamondTrap " << this->_name << " has been constructed From another DiamondTrap!\033[0m" << std::endl;
	std::cout << "\033[1;34mHit points \033[0m" << this->_hit << std::endl;
	std::cout << "\033[1;34mEnergy energy \033[0m" << this->_energy << std::endl;
	std::cout << "\033[1;34mAttack points \033[0m" << this->_attack << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "\033[1;34mDiamondTrap " << this->_name << " has been destroyed!!\033[0m" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
		std::cout << "\033[1;34mDiamondTrap " << this->_name << " has been equalized to other\033[0m" << std::endl;
	}
	else
		std::cout << "\033[1;34mDiamondTrap " << this->_name << " Cannot be equalized to itself\033[0m" << std::endl;
	return(*this);
}


void	DiamondTrap::attack(const std::string &target){
	if (this->_energy <= 0){
		std::cout << "\033[1;34mScavTrap " << this->_name << " has no energy to attack.\033[0m" << std::endl;
		return;
	}
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){
	std::cout << "\033[1;34mHi! My name is \033[0m" << this->_name << "\033[1;34m and I have a ClapTrap named.\033[0m" << ClapTrap::_name << std::endl;
	std::cout << "\033[1;34mIt itches alot!\033[0m";
}

std::string	DiamondTrap::getName() const{
	return (this->_name);
}