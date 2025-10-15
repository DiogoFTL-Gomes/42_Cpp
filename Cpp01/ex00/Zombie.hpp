#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie{

	public:
		Zombie(void);
		~Zombie(void);

		void	announc(void) const;

	private:
		std::string	_name;
};

#endif