#include "Zombie.hpp"
#include <iostream>

int	main(void){
	Zombie	*horde;
	Zombie	*meat;
	int		many;
	int		lots;

	many = 5;
	lots = 500000000;//Rigged to fail!!
	horde = zombieHorde(many, "Zombie n#");
	meat = zombieHorde(lots, "Meat Shield n#");
	if (horde){
		delete[] horde;
	}
	if (meat){
		delete[] meat;
	}
	return (0);
}
