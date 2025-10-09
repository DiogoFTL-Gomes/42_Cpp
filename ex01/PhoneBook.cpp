#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void){
	std::cout << "phonebook created" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "phonebook destroyed" << std::endl;
	return;
}