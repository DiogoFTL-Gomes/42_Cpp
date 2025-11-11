#include "Cat.hpp"

Cat::Cat() : AAnimal(){
	this->_type = "\033[1;34mCat\033[0m";
	this->_catBrain = new Brain();
	std::cout << "A " << this->_type << " created itself!" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other){
	this->_type = other._type;
	this->_catBrain = new Brain(*other._catBrain);
	std::cout << "A Cat copy constructor has been called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other){
	if (this != &other){
		std::cout << this->_type << " reluctantly becomes a ";
		this->_type = other._type;
		delete (this->_catBrain);
		this->_catBrain = new Brain(*other._catBrain);
		std::cout << this->_type << " with an equal overload" << std::endl;
	}
	return (*this);
}

Cat::~Cat(){
	delete (this->_catBrain);
	std::cout << this->_type << " is being destroyed. There's fur everywhere!!" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "Meow!! MeaW!! eHSSSS!!!!" << std::endl;
}

void	Cat::addIdea(const std::string &idea){
	int	pos = this->_catBrain->addIdea(idea);
	if (pos >= 0){
		std::cout << "New idea implanted on slot " << pos << " of cat brain." << std::endl;
	}
	else{
		std::cout << "Cat Brain is full of bad ideas!" << std::endl;
	}
}

std::string	Cat::rememberIdea(int index) const{
	if (this->_catBrain->getIdea(index).empty())
		return ("This area of the cat brain is full of air!!");
	else
		return (this->_catBrain->getIdea(index));
}

Cat*	Cat::clone() const {
	std::cout << this->getType() << " has being cloned! SCIENCE!!" << std::endl;
	return new Cat(*this);
}
