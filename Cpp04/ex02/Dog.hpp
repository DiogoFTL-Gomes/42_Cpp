#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Dog : public AAnimal{

	private:
		Brain	*_dogBrain;

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void	makeSound() const;
		void	addIdea(const std::string &idea);
		std::string	rememberIdea(int index) const;
};

#endif