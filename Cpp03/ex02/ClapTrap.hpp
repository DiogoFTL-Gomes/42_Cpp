#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class	ClapTrap{

//Private is now protected so children can access it.
	protected:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	getName() const;
		void	announceAttributes() const;

};

#endif