#include <iostream>
#include "ClapTrap.hpp"

int	main(void){
	std::cout << "\033[1;35m##### Giving name to Claptrap #####\033[0m" << std::endl;
	ClapTrap	uno("\033[1;34mGarcia\033[0m");
	uno.announceAttributes();
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating nameless Claptrap #####\033[0m" << std::endl;
	ClapTrap	dos;
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Claptrap to another Claptrap #####\033[0m" << std::endl;
	dos = uno;
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Creating nameless Claptrap #####\033[0m" << std::endl;
	ClapTrap	tres("\033[1;32mJulio\033[0m");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Claptrap to another Claptrap #####\033[0m" << std::endl;
	dos = tres;
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Equalizing Claptrap to a temp Claptrap #####\033[0m" << std::endl;
	dos = ClapTrap("\033[1;31mManuel\033[0m");
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Claptrap 'attacks' another Claptrap #####\033[0m" << std::endl;
	uno.attack(dos.getName());
	std::cout << std::endl;
	
	std::cout << "\033[1;35m##### Claptrap repairs itself #####\033[0m" << std::endl;
	dos.takeDamage(0);
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Claptrap 'attacks' another Claptrap #####\033[0m" << std::endl;
	dos.attack(tres.getName());
	std::cout << std::endl;

	std::cout << "\033[1;35m##### Claptrap repairs itself #####\033[0m" << std::endl;
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
	std::cout << std::endl;

	std::cout << "\033[1;35m##### It's KILLING TIME!!! #####\033[0m" << std::endl;
	return 0;
}
