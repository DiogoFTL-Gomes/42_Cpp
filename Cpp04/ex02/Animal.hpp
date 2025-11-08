#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class AAnimal{

	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal	&operator=(const AAnimal &other);
		virtual ~AAnimal();

		std::string		getType() const ;

		virtual void	makeSound() const = 0;
		virtual void	addIdea(const std::string &idea) = 0;
		virtual std::string	rememberIdea(int index) const = 0;
};


#endif