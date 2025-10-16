#include "Zombie.hpp"
#include <iostream>

int	main(void){
	Zombie	*horde;
	Zombie	*meat;

	horde = zombieHorde(5, "Zombie n#");
	meat = zombieHorde(500000000, "Meat Shield n#");
	if (horde){
		delete[] horde;
	}
	if (meat){
		delete[] meat;
	}
	return (0);
}
