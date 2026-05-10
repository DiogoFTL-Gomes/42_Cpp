#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	std::cout << "\033[1;35m##### Creating nameless Fragtrap #####\033[0m" << std::endl;
	FragTrap	uno;
	uno.announceAttributes();
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Fragtrap from another Fragtrap #####\033[0m" << std::endl;
	FragTrap	dos(uno);
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Fragtrap with a name #####\033[0m" << std::endl;
	FragTrap	tres("Mel");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Fragtrap to a new Fragtrap #####\033[0m" << std::endl;
	uno = FragTrap("Leite");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Fragtrap to a new Fragtrap #####\033[0m" << std::endl;
	dos = FragTrap("Canela");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating Claptrap & Scavtrap for battle #####\033[0m" << std::endl;
	ClapTrap	exampleA("Sal");
	ScavTrap	exampleB("Salsa");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Fragtrap attacks #####\033[0m" << std::endl;
	uno.attack(dos.getName());
	std::cout << "\033[1;35m##### Claptrap attacks #####\033[0m" << std::endl;
	exampleA.attack(dos.getName());
	std::cout << "\033[1;35m##### Scavtrap attacks #####\033[0m" << std::endl;
	exampleB.attack(dos.getName());
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Fragtrap tries to make peace #####\033[0m" << std::endl;
	dos.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
