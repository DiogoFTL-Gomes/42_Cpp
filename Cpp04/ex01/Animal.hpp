#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal{

	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		virtual ~Animal();

		std::string		getType() const ;

		virtual void	makeSound() const;
		virtual void	addIdea(const std::string &idea);
		virtual std::string	rememberIdea(int index) const;
		virtual Animal* clone() const = 0;
};


#endif