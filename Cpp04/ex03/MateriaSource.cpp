#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->_storage[i] = NULL;
	std::cout << "An empty MateriaSource has been created" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other){
	for (int i = 0; i < 4; i++)
		this->_storage[i] = NULL;
	*this = other;
	std::cout << "An empty MateriaSource has been created" << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other){
	if (this != &other){
		for (int i = 0; i < 4; i++){
			delete (this->_storage[i]);
			this->_storage[i] = NULL;
			if (other._storage[i])
				this->_storage[i] = other._storage[i]->clone();
		}
	}
	std::cout << "A MateriaSource has been copied" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		delete (this->_storage[i]);
	std::cout << "A MateriaSource has been delete along with all its knowledge" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m){
	if (!m)
		return;
	for (int i = 0; i < 4; i++){
		if (this->_storage[i] == NULL){
			this->_storage[i] = m;
			std::cout << "MateriaSource has learned to make " << this->_storage[i]->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource has no space to learn " << m->getType() << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if (this->_storage[i] && this->_storage[i]->getType() == type)
			return this->_storage[i]->clone();
	}
	return (NULL);
}