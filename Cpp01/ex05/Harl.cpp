#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){
}

Harl::~Harl(void){
}

void	Harl::_debug(void){
	std::cout << "\033[1;35m[DEBUG]\033[0m" << std::endl;
	std::cout << "-> Your current problem seems to originate somewhere between the keyboard and the chair." << std::endl << std::endl;
}
void	Harl::_info(void){
	std::cout << "\033[1;33m[INFO]\033[0m" << std::endl;
	std::cout << "-> While engaging in C programing please refrain  from:\n	-Not freeing allocated memory\n	-Writing spaggetti code\n	-Driving\n Thank you for your understanding" << std::endl << std::endl;
}
void	Harl::_warning(void){
	std::cout << "\033[1;32m[WARNING]\033[0m" << std::endl;
	std::cout << "-> This program has had beans for his last meal. Lots of beans...\nYou have been warned!!" << std::endl << std::endl;
}
void	Harl::_error(void){
	std::cout << "\033[1;31m[ERROR]\033[0m" << std::endl;
	std::cout << "->	I like big butts and I cannot lie\n	You other brothers can't deny\n	That when a girl walks in**LOUD RECORD SCRATCHING SOUND**\n...You saw nothing, heard nothing, dig?!?!" << std::endl << std::endl;
}

void	Harl::complain(std::string level){
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
		};

	for (int i = 0; i < 4; i++){
		if (levels[i] == level){
			(this->*functions[i])();
			return;
		}
	}
	std::cout << '"' << level << "\" means nothing to Harl!!" << std::endl;
	std::cout << "Harl accepts only \033[1;35m[DEBUG]\033[1;33m[INFO]\033[1;32m[WARNING]\033[1;31m[ERROR]\033[0m as inputs" << std::endl;
	return;
}
