#include "Zombie.hpp"
#include <iostream>

int	main(void){
	Zombie	*heapZombie = newZombie("Roberto");

	heapZombie->announce();
	delete heapZombie;

	heapZombie = newZombie("Alberto");
	heapZombie->announce();

	randomChump("Ricardo");

	delete heapZombie;

	return (0);
}