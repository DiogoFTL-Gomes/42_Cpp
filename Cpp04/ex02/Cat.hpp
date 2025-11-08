#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Cat : public AAnimal{

	private:
		Brain	*_catBrain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		void	makeSound() const;
		void	addIdea(const std::string &idea);
		std::string	rememberIdea(int index) const;
};

#endif