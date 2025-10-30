#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	std::cout << "\033[1;35m##### Creating nameless Scavtrap #####\033[0m" << std::endl;
	ScavTrap	uno;
	uno.announceAttributes();
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Scavtrap from another Scavtrap #####\033[0m" << std::endl;
	ScavTrap	dos(uno);
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Scavtrap with a name #####\033[0m" << std::endl;
	ScavTrap	tres("RRRoberrtoo");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Scavtrap to a new Scavtrap #####\033[0m" << std::endl;
	uno = ScavTrap("Maria");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Scavtrap to a new Scavtrap #####\033[0m" << std::endl;
	dos = ScavTrap("Domingos");
	std::cout << std::endl;

	uno.attack(dos.getName());
	std::cout << std::endl;

	dos.guardGate();
	std::cout << std::endl;

	return (0);
}
