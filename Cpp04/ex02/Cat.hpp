#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include <iostream>
#include "Brain.hpp"

class Cat : public AAnimal{

	private:
		Brain	*_catBrain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		virtual void	makeSound() const;
		virtual void	addIdea(const std::string &idea);
		virtual std::string	rememberIdea(int index) const;
		virtual Cat* clone() const;
};

#endif