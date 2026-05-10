#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->_type = "\033[1;36mWrongCat\033[0m";
	std::cout << "A " << this->_type << " created itself!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	this->_type = other._type;
	std::cout << "A WrongCat copy constructor has been called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other){
	if (this != &other){
		std::cout << this->_type << " reluctantly becomes a ";
		this->_type = other._type;
		std::cout << this->_type << " with an equal overload" << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << this->_type << " is being destroyed. There's fur everywhere!!" << std::endl;
}

void	WrongCat::makeSound() const{
	std::cout << "Moooooooh !! Moooooooooh!!" << std::endl;
}
