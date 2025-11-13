#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " comes into existance" << std::endl;
}

Character::Character(Character const &other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_copyInventory(other);
}

Character	&Character::operator=(Character const &other) {
	if (this != &other){
		this->_name = other._name;
		_clearInventory();
		_copyInventory(other);
	}
	return (*this);
}

Character::~Character(){
	this->_clearInventory();
	std::cout << this->_name << " fades from existance..." << std::endl;
}

void	Character::_clearInventory(){
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i]){
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}
}

void	Character::_copyInventory(Character const &other){
	for (int i = 0; i < 4; i++){
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
}


std::string const	&Character::getName() const{
	return (this->_name);
}

void	Character::equip(AMateria *m){
	if (!m)
		return;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == NULL){
			this->_inventory[i] = m;
			std::cout << this->_name << " equiped " << this->_inventory[i]->getType() << " Materia" << std::endl;
			return;
		}
	}
	std::cout << this->_name << "'s inventory is full" << std::endl;
}

void	Character::unequip(int index){
	if (index < 0 || index >= 4 || !this->_inventory[index])
		return;
	this->_inventory[index] = NULL;
}

void	Character::use(int index, ICharacter &target){
	if (index < 0 || index >= 4 || !this->_inventory[index])
		return;
	this->_inventory[index]->use(target);
}

void	Character::use(std::string type, ICharacter &target){
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] && this->_inventory[i]->getType() == type){
			this->_inventory[i]->use(target);
			return;
		}
	}
	std::cout << this->_name << " does not have \"" << type << "\" Materia in inventory!" << std::endl;
}
