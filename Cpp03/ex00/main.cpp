#include <iostream>
#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	uno("\033[1;34mGarcia\033[0m");
	std::cout << std::endl;

	ClapTrap	dos;
	std::cout << std::endl;

	dos = uno;
	std::cout << std::endl;

	ClapTrap	tres("\033[1;32mJulio\033[0m");
	std::cout << std::endl;

	dos = tres;
	std::cout << std::endl;

	dos = ClapTrap("\033[1;31mManuel\033[0m");
	std::cout << std::endl;

	uno.attack(dos.getName());
	dos.takeDamage(0);
	dos.attack(tres.getName());
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	tres.beRepaired(5);
	return 0;
}
