#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	ScavTrap	uno;
	std::cout << std::endl;

	ScavTrap	dos(uno);
	std::cout << std::endl;

	ScavTrap	tres("\033[1;34mRRRoberrtoo\033[0m");
	std::cout << std::endl;

	uno = ScavTrap("\033[1;35mMaria\033[0m");
	std::cout << std::endl;

	dos = ScavTrap("\033[1;36mDomingos\033[0m");
	std::cout << std::endl;

	uno.attack(dos.getName());
	std::cout << std::endl;

	dos.guardGate();
	std::cout << std::endl;

	return (0);
}
