#include "Brain.hpp"

Brain::Brain(){
	std::cout << "A brain has been constructed" << std::endl;
}

Brain::Brain(const Brain &other){
	for (int i = 0; i < 100; i++){
		this->setIdeia(i, other.getIdeia(i));
	}
	std::cout << "A brain has been copied" << std::endl;
}

Brain	&Brain::operator=(const Brain &other){
	if (this != &other)
	{
		for (int i = 0; i < 100; i++){
			this->setIdeia(i, other.getIdeia(i));
		}
		std::cout << "A brain has been equalized to another" << std::endl;
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "A brain has been lobotomized" << std::endl;
}


std::string	Brain::getIdeia(int index) const{
	if (index >= 0 && index < 100){
		return (this->ideias[index]);
	}
	return ("");
}

void	Brain::setIdeia(int index, const std::string &otherIdeia){
	if (index >= 0 && index < 100){
		this->ideias[index] = otherIdeia;
	}
}

