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
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName){
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName){
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber){
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret){
	this->_darkestSecret = darkestSecret;
}


std::string	Contact::getFirstName() const{
	return (this->_firstName);
}

std::string	Contact::getLastName() const{
	return (this->_lastName);
}

std::string	Contact::getNickName() const{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber() const{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret() const{
	return (this->_darkestSecret);
}
