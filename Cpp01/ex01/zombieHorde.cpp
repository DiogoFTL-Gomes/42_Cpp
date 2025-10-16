#include "Zombie.hpp"
#include <sstream>
#include <new>

Zombie	*zombieHorde(int n, std::string name){
	Zombie	*horde;

	if (n <= 0){
		std::cout << "Invalid Horde size!" << std::endl;
		return (NULL);
	}
	if (name.empty()){
		name = "(Nameless zombie )";
	}

	horde = new (std::nothrow) Zombie[n];
	if (!horde){
		std::cout << "Failed to allocate zombieHorde!" << std::endl;
		return (NULL);
	}

	for (int i = 0; i < n; i++){
		std::stringstream	ss;
		ss << (i + 1);
		horde[i].setName("\033[1;32m" + name + ss.str() + "\033[0m");
	}
	return (horde);
}
