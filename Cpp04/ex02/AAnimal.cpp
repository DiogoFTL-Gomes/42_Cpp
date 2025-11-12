#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("\033[1;32mBlob of biomass\033[0m") {
	std::cout << "A " << this->_type << " AAnimal constructor created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type){
	std::cout << "AAnimal copy constructor called on a " << this->_type << " AAnimal" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &other){
	if (this != &other){
		std::cout << this->getType() << " AAnimal has been turned into a ";
		this->_type = other._type;
		std::cout << this->getType() << " AAnimal with a equal operator" << std::endl;
	}
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout <<"AAnimal destructor has been called on a " << this->getType() << std::endl;
}

std::string	AAnimal::getType() const{
	return (this->_type);
}
/*
void	AAnimal::makeSound() const{
	std::cout << "Horrible screeching noise from a " << this->getType() << std::endl;
}

void	AAnimal::addIdea(const std::string &idea){
	(void)idea;
	std::cout << this->getType() << " cannot hold ideas...thankfully" << std::endl;
}

std::string	AAnimal::rememberIdea(int index) const{
	(void)index;
	std::cout << this->getType() << " has no brain...isn't it obvious?!?" << std::endl;
	return ("");
}
	*/