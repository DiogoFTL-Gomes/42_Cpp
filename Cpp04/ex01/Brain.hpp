#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class	Brain{

	private:
		std::string ideias[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		~Brain();

	std::string	getIdeia(int index) const;
	void		setIdeia(int index, const std::string &otherIdeia);
};

#endif