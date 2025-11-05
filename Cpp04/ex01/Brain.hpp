#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class	Brain{
	public:
		Brain();
		Brain(Brain &other);
		Brain	&operator=(Brain &other);
		~Brain();

		std::string ideias[100];
};

#endif