#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[]){
	if (argc != 2){
		std::cout << "Harl needs just one argument!!" << std::endl;
		std::cout << "Harl accepts only \033[1;35m[DEBUG]\033[1;33m[INFO]\033[1;32m[WARNING]\033[1;31m[ERROR]\033[0m as inputs" << std::endl;
		return (1);
	}
	std::string	level;
	Harl	test;
	level = argv[1];
	test.complain(level);
	return 0;
}
