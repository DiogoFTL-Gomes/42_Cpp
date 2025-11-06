#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->_type = "\033[1;33mDog\033[0m";
	std::cout << "A " << this->_type << " has been created!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other){
	this->_type = other._type;
	std::cout << "A Dog copy constructor has been called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other){
	if (this != &other){
		std::cout << this->_type << " has been turned into another ";
		this->_type = other._type;
		std::cout << this->_type << " with an equal operator" << std::endl;
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << this->_type << " is being destroyed. So sad :(" << std::endl;
}

void	Dog::makeSound() const{
	std::cout << "Woof!! Woof!!" << std::endl;
}
