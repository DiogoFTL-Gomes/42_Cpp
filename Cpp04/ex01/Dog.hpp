#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Dog : public Animal{

	private:
		Brain	*_dogBrain;

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog();

		virtual void	makeSound() const;
		virtual void	addIdea(const std::string &idea);
		virtual std::string	rememberIdea(int index) const;
		virtual Dog* clone() const;
};

#endif