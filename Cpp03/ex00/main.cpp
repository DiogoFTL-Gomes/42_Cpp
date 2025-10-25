#include <iostream>
#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	uno("Garcia");
	ClapTrap	dos(uno);

	ClapTrap	tres("Julio");
	dos = tres;
	dos = ClapTrap("Manuel");
	uno.attack(dos.getName());
	dos.takeDamage(0);
	dos.attack(tres.getName());
	tres.beRepaired(5);
	return 0;
}
