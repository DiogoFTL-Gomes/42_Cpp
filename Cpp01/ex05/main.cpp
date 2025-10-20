#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[]){
	if (argc < 2){
		std::cout << "Harl need at least one argument!!" << std::endl;
		std::cout << "Harl accepts only [DEBUG][INFO][WARNING][ERROR] as inputs" << std::endl;
		return (1);
	}
	std::string	level;
	Harl	test;
	for (int i = 1; i < argc; i++){
		level = argv[i];
		test.complain(level);
	}
	return 0;
}
