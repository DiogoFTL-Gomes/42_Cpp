#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->_type = "\033[1;34mCat\033[0m";
	this->_dumbIdeias = new Brain();
	std::cout << "A " << this->_type << " created itself!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other){
	this->_type = other._type;
	this->_dumbIdeias = new Brain(*other._dumbIdeias);
	std::cout << "A Cat copy constructor has been called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other){
	if (this != &other){
		std::cout << this->_type << " reluctantly becomes a ";
		this->_type = other._type;
		delete (this->_dumbIdeias);
		this->_dumbIdeias = new Brain(*other._dumbIdeias);
		std::cout << this->_type << " with an equal overload" << std::endl;
	}
	return (*this);
}

Cat::~Cat(){
	delete (this->_dumbIdeias);
	std::cout << this->_type << " is being destroyed. There's fur everywhere!!" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "Meow!! MeaW!! eHSSSS!!!!" << std::endl;
}
