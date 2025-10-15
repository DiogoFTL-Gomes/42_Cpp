#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook(void){
	this->_nbr_contacts = 0;
	return;
}

PhoneBook::~PhoneBook(void){
	return;
}

void	PhoneBook::set_contacts(std::string *values, int i){
	this->_contacts[i].setFirstName(values[0]);
	this->_contacts[i].setLastName(values[1]);
	this->_contacts[i].setNickName(values[2]);
	this->_contacts[i].setPhoneNumber(values[3]);
	this->_contacts[i].setDarkestSecret(values[4]);
	this->_add_current_contacts();
}

std::string	PhoneBook::get_contacts(int slot, t_field field){
	if (field == FIRSTN)
		return (this->_contacts[slot].getFirstName());
	if (field == LASTN)
		return (this->_contacts[slot].getLastName());
	if (field == NICKN)
		return (this->_contacts[slot].getNickName());
	if (field == NUMBER)
		return (this->_contacts[slot].getPhoneNumber());
	if (field == DARKS)
		return (this->_contacts[slot].getDarkestSecret());
	else
		return (NULL);
}

void	PhoneBook::_add_current_contacts(){
	if (_nbr_contacts < 8){
		_nbr_contacts++;
		if (_total_contacts < 8){
			_total_contacts++;
		}
	}
	if (_nbr_contacts == 8){
		_nbr_contacts = 0;
	}
	return;
}

int		PhoneBook::get_nbr_contacts() const{
	return (_nbr_contacts);
}
int		PhoneBook::get_total_contacts() const{
	return (_total_contacts);
}
