#include "Brain.hpp"

Brain::Brain(){
	std::cout << "A brain has been constructed" << std::endl;
}

Brain::Brain(const Brain &other){
	for (int i = 0; i < MAX_IDEAS; i++){
		this->setIdea(i, other.getIdea(i));
	}
	std::cout << "A brain has been copied" << std::endl;
}

Brain	&Brain::operator=(const Brain &other){
	if (this != &other)
	{
		for (int i = 0; i < MAX_IDEAS; i++){
			this->setIdea(i, other.getIdea(i));
		}
		std::cout << "A brain has been equalized to another" << std::endl;
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "A brain has been lobotomized" << std::endl;
}


std::string	Brain::getIdea(int index) const{
	if (index >= 0 && index < MAX_IDEAS){
		if (!this->ideas[index].empty()){
			return (this->ideas[index]);
		}
	}
	return ("");
}

void	Brain::setIdea(int index, const std::string &otherIdea){
	if (index >= 0 && index < MAX_IDEAS){
		this->ideas[index] = otherIdea;
	}
}

int	Brain::addIdea(const std::string &newIdea){
	for (int i = 0; i < MAX_IDEAS; i++){
		if (this->ideas[i].empty()){
			this->setIdea(i, newIdea);
			return (i);
		}
	}
	return (-1);
}