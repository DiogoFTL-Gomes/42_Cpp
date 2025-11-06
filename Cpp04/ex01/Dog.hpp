#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Dog : public Animal{

	private:
		Brain	*_dumbIdeias;

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void	makeSound() const;
};

#endif