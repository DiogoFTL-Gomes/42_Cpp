#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate();

		static const int	sci_hit = 100;
		static const int	sci_energy = 50;
		static const int	sci_attack = 20;
};

#endif