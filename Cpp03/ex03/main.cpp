#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){
	std::cout << "\033[1;35m##### Creating nameless Fragtrap #####\033[0m" << std::endl;
	DiamondTrap	uno;
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Fragtrap from another Fragtrap #####\033[0m" << std::endl;
	DiamondTrap	dos(uno);
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Fragtrap with a name #####\033[0m" << std::endl;
	FragTrap	tres("Mel");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Fragtrap to a new Fragtrap #####\033[0m" << std::endl;
	uno = DiamondTrap("Leite");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Fragtrap to a new Fragtrap #####\033[0m" << std::endl;
	dos = DiamondTrap("Canela");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Dealing Attacking #####\033[0m" << std::endl;
	uno.attack(dos.getName());
	std::cout << std::endl;

	std::cout << "\033[1;35m##### It's KILLING TIME!!! #####\033[0m" << std::endl;
	return (0);
}
