#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[]){
	if (argc != 2){
		std::cout << "Harl needs just one argument!!" << std::endl;
		return (1);
	}
	std::string	level;
	Harl	test;
	level = argv[1];
	test.complain(level);
	return 0;
}
