#include "Zombie.hpp"
#include <iostream>

void	StackHeapZombies(void){
	Zombie	*bunchZombies[4];

	std::cout << std::endl;
	bunchZombies[0] = newZombie("\033[1;32mBunch Zombie 01\033[0m");
	bunchZombies[1] = newZombie("\033[1;32mBunch Zombie 02\033[0m");
	bunchZombies[2] = newZombie("\033[1;32mBunch Zombie 03\033[0m");
	bunchZombies[3] = newZombie("\033[1;32mBunch Zombie 04\033[0m");

	delete bunchZombies[3];
	Zombie	stack_zombie1("\033[1;33mStack Zombie 01\033[0m");
	delete bunchZombies[1];
	Zombie	stack_zombie2("\033[1;33mStack Zombie 02\033[0m");
	delete bunchZombies[0];
	Zombie	stack_zombie3("\033[1;33mStack Zombie 03\033[0m");
	delete bunchZombies[2];
	Zombie	stack_zombie4("\033[1;33mStack Zombie 04\033[0m");
}

int	main(void){
	Zombie	*heapZombie;

	std::cout << "\033[1;32mGreen\033[0m is in \033[1;32mHeap\033[0m" << std::endl;
	std::cout << "\033[1;33mYellow\033[0m is in \033[1;33mStack\033[0m" << std::endl << std::endl;

	heapZombie = newZombie("\033[1;32mAndré\033[0m");
	delete heapZombie;
	randomChump("\033[1;33mRúben\033[0m");
	heapZombie = newZombie("\033[1;32mClaudia\033[0m");
	randomChump("\033[1;33mPablo\033[0m");
	delete heapZombie;

	StackHeapZombies();

	return (0);
}