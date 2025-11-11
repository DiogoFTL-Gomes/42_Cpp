#include "Dog.hpp"

Dog::Dog() : AAnimal(){
	this->_type = "\033[1;33mDog\033[0m";
	this->_dogBrain = new Brain();
	std::cout << "A " << this->_type << " has been created!" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other){
	this->_type = other._type;
	this->_dogBrain = new Brain(*other._dogBrain);
	std::cout << "A Dog copy constructor has been called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other){
	if (this != &other){
		std::cout << this->_type << " has been turned into another ";
		this->_type = other._type;
		delete (this->_dogBrain);
		this->_dogBrain = new Brain(*other._dogBrain);
		std::cout << this->_type << " with an equal operator" << std::endl;
	}
	return (*this);
}

Dog::~Dog(){
	delete (this->_dogBrain);
	std::cout << this->_type << " is being destroyed. So sad :(" << std::endl;
}

void	Dog::makeSound() const{
	std::cout << "Woof!! Woof!!" << std::endl;
}

void	Dog::addIdea(const std::string &idea){
	int	pos = this->_dogBrain->addIdea(idea);
	if (pos >= 0){
		std::cout << "New idea implanted on slot " << pos << " of dog brain." << std::endl;
	}
	else{
		std::cout << "Dog Brain is full of bad ideas!" << std::endl;
	}
}

std::string	Dog::rememberIdea(int index) const{
	if (this->_dogBrain->getIdea(index).empty())
		return ("This area of the dog brain is full of air!!");
	else
		return (this->_dogBrain->getIdea(index));
}

Dog *	Dog::clone() const {
	std::cout << this->getType() << " has being cloned! SCIENCE!!" << std::endl;
	return new Dog(*this);
}
