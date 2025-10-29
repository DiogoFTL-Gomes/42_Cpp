#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

		int	_p_hit;
		int	_p_energy;
		int	_p_attack;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &other);

		static const int	sci_hit = 100;
		static const int	sci_energy = 100;
		static const int	sci_attack = 30;

		void	highFivesGuys();

};

#endif