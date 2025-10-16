#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name){
	Zombie	*horde;

	if (n <= 0)
		return (NULL);
	horde = new (std::nothrow) Zombie[n];
	if (!horde){
		std::cerr << "Failed to allocate horde" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < n; i++){
		horde[i].setName("\033[1;32m" + name + std::to_string(i + 1) + "\033[0m");
	}
	return (horde);
}