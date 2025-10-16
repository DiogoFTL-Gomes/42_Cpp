#include "Zombie.hpp"
#include <iostream>

int	main(void){
	Zombie	*horde;

	horde = zombieHorde(5, "Zombie n#");
	if (!horde){
		return (std::cout << "No Zombies in sight" << std::endl, 0);
	}
	delete[] horde;
	return (0);
}