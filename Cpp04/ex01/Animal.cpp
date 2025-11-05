#include "Animal.hpp"

Animal::Animal() : _type("\033[1;32mBlob of biomass\033[0m") {
	std::cout << "A " << this->_type << " Animal constructor created" << std::endl;
}

Animal::Animal(const Animal &other){
	*this = other;
	std::cout << "Animal copy constructor called on a " << this->_type << " _type Animal" << std::endl;
}

Animal	&Animal::operator=(const Animal &other){
	std::cout << this->getType() << " Animal has been turned into a ";
	*this = other;
	std::cout << this->getType() << " Animal with a equal operator" << std::endl;
	return (*this);
}

Animal::~Animal(){
	std::cout <<"Animal destructor has been called on a " << this->getType() << std::endl;
}

std::string	Animal::getType() const{
	return (this->_type);
}

void	Animal::makeSound() const{
	std::cout << "Horrible screeching noise from a " << this->getType() << std::endl;
}