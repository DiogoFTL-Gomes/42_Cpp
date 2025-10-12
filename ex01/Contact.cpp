#include "Contact.hpp"
#include <iostream>

Contact::Contact(void){
	//std::cout << "Contact created" << std::endl;
	//std::cout << std::hex << (long)&this->_first_name << std::endl;
	return;
}

Contact::~Contact(void){
	//std::cout << "Contact destroyed" << std::endl;
	return;
}

void	Contact::setFirstName(std::string firstName){
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName){
	_lastName = lastName;
}

void	Contact::setNickName(std::string nickName){
	_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber){
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret){
	_darkestSecret = darkestSecret;
}