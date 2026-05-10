#include "Zombie.hpp"
#include <iostream>

int	main(void){
	Zombie	*horde;
	int		many;

	many = 5;
	horde = zombieHorde(many, "Zombie n#");
	if (horde){
		delete[] horde;
	}
	return (0);
}
