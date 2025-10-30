#include <iostream>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){
	std::cout << "\033[1;35m##### Creating nameless DiamondTrap #####\033[0m" << std::endl;
	DiamondTrap	uno;
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating DiamondTrap from another DiamondTrap #####\033[0m" << std::endl;
	DiamondTrap	dos(uno);
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating DiamondTrap with a name #####\033[0m" << std::endl;
	DiamondTrap	tres("Mel");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing DiamondTrap to a new DiamondTrap #####\033[0m" << std::endl;
	uno = DiamondTrap("Leite");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing DiamondTrap to a new DiamondTrap #####\033[0m" << std::endl;
	dos = DiamondTrap("Canela");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Attacking #####\033[0m" << std::endl;
	uno.attack(dos.getDiamondName());
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Attacking its father #####\033[0m" << std::endl;
	uno.attack(dos.getName());
	std::cout << std::endl;

	std::cout << "\033[1;35m##### DiamondTrap looks for his ancestors #####\033[0m" << std::endl;
	dos.whoAmI();
	std::cout << std::endl;

	std::cout << "\033[1;35m##### It's KILLING TIME!!! #####\033[0m" << std::endl;
	return (0);
}
