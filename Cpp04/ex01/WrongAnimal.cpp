#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("\033[1;35mCube of biomass\033[0m") {
	std::cout << "A " << this->_type << " WrongAnimal constructor created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor called on a " << this->_type << " _type WrongAnimal" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other){
	if (this != &other){
		std::cout << this->getType() << " WrongAnimal has been turned into a ";
		this->_type = other._type;
		std::cout << this->getType() << " WrongAnimal with a equal operator" << std::endl;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout <<"WrongAnimal destructor has been called on a " << this->getType() << std::endl;
}

std::string	WrongAnimal::getType() const{
	return (this->_type);
}

void	WrongAnimal::makeSound() const{
	std::cout << "Terrifying screeching howl from a " << this->getType() << std::endl;
}