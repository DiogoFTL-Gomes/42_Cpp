#include "Contact.hpp"
#include <iostream>

Contact::Contact(void){
	std::cout << "Contact created" << std::endl;
	return;
}

Contact::~Contact(void){
	std::cout << "Contact destroyed" << std::endl;
	return;
}

