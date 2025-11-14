#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name), _indexBag(0) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " comes into existance" << std::endl;
}

Character::Character(Character const &other) : _name(other._name + "_copy"), _indexBag(0) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_copyInventory(other);
	this->_copyBag(other);
}

Character	&Character::operator=(Character const &other) {
	if (this != &other){
		this->_name = other._name + "_copy";
		this->_clearInventory();
		this->_copyInventory(other);
		this->_clearBag();
		this->_copyBag(other);
	}
	return (*this);
}

Character::~Character(){
	this->_clearInventory();
	this->_clearBag();
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

void	Character::_clearBag(){
	for (int i = 0; i < this->_indexBag; i++){
		delete (this->_bag[i]);
		this->_bag[i] = NULL;
	}
}

void	Character::_copyInventory(Character const &other){
	for (int i = 0; i < 4; i++){
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

void	Character::_copyBag(Character const &other){
	for (int i = 0; i < other._indexBag; i++){
		this->_bag[i] = other._bag[i]->clone();
	}
	this->_indexBag = other._indexBag;
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
	std::cout << this->_name << "'s inventory is full. " << m->getType() << " drops to the ground and is destroyed." << std::endl;
	delete (m);
	m = NULL;
}

void	Character::unequip(int index){
	if (index < 0 || index >= 4 || !this->_inventory[index]){
		std::cout << "Nothing to unequip in" << this->getName() << "'s inventory slot " << index << std::endl;
		return;
	}
	if (this->_indexBag < 100){
		this->_bag[_indexBag++] = this->_inventory[index];
	}
	else{
		delete (this->_bag[99]);
		this->_bag[99] = this->_inventory[index];
	}
	this->_inventory[index] = NULL;
	std::cout << this->getName() << "'s inventory slot " << index << " is empty" << std::endl;
}

void	Character::use(int index, ICharacter &target){
	if (index < 0 || index >= 4 || !this->_inventory[index]){
		std::cout << this->getName() << "'s slot " << index << " is empty" << std::endl;
		return;
	}
	this->_inventory[index]->use(target);
	delete (this->_inventory[index]);
	this->_inventory[index] = NULL;
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
