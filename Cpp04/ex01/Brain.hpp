#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define MAX_IDEAS 100

class	Brain{

	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		~Brain();

	std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string &otherIdea);
	int			addIdea(const std::string &newIdea);
};

#endif