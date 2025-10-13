#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void){
	//std::cout << "phonebook created" << std::endl;
	this->_nbr_contacts = 0;
	return;
}

PhoneBook::~PhoneBook(void){
	//std::cout << "phonebook destroyed" << std::endl;
	return;
}

static bool	is_number(const std::string line){
	for (int i = 0; i < line.length(); i++){
		if (!std::isdigit(line[i]))
			return (false);
	}
	return (true);
}

static std::string	formatField(std::string field){
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return (field);
}

void	PhoneBook::search_draw(void) const{

	std::system("clear");
	std::cout << "\033[1;36m                                                                                        " << std::endl;
	std::cout << "===================================================================================================" << std::endl;
	std::cout << "          ███████\033[1;31m╗\033[1;36m███████\033[1;31m╗ \033[1;36m█████\033[1;31m╗ \033[1;36m██████\033[1;31m╗  \033[1;36m██████\033[1;31m╗\033[1;36m██\033[1;31m╗  \033[1;36m██\033[1;31m╗     " << std::endl;
	std::cout << "          \033[1;36m██\033[1;31m╔════╝\033[1;36m██\033[1;31m╔════╝\033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m╗\033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m╗\033[1;36m██\033[1;31m╔════╝\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;36m███████\033[1;31m╗\033[1;36m█████\033[1;31m╗  \033[1;36m███████\033[1;31m║\033[1;36m██████\033[1;31m═╣\033[1;36m██\033[1;31m║     \033[1;36m███████\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;31m╚════\033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m╔══╝  \033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m║     \033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;36m███████\033[1;31m║\033[1;36m███████\033[1;31m╗\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║╚\033[1;36m██████\033[1;31m╗\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;31m╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝     " << std::endl;
	std::cout << "\033[1;36m===================================================================================================\033[0m" << std::endl;
	return;
}

void	PhoneBook::search_print() const{

	if (this->_get_nbr_contacts() == 0){
		this->search_draw();
		std::cout << "\033[0mPhoneBook has no contacts." << std::endl;
		std::cout << "Type \033[1;31mBACK\033[0m to return:";
	}
	else{
		this->search_draw();
		std::cout << "\033[1;31m |First name| Last name| Nickname | Phone nbr|DarkSecret|\033[0m" << std::endl;
		for (int i = 0; i < this->_get_nbr_contacts(); i++){
			std::cout << i + 1 << "\033[1;31m|\033[0m" << std::setw(10) << formatField(this->_contacts[i].getFirstName());
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(this->_contacts[i].getLastName());
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(this->_contacts[i].getNickName());
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(this->_contacts[i].getPhoneNumber());
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(this->_contacts[i].getDarkestSecret());
			std::cout << "\033[1;31m|\033[0m" << std::endl;
		}
		std::cout << "Type \033[1;31mBACK\033[0m to return:";
	}

	return ;
}



int		PhoneBook::search_menu(void) const{

	std::string	input;
	int			slot;

	this->search_print();
	while (1)
	{
		if (!std::getline(std::cin, input))
			return (this->eof_input(), 1);

		if (input.empty()){
			this->search_print();
			std::cout << "Input cannot be empty!" << std::endl;
			continue;
		}

		if (input == "BACK"){
			return (0);
		}

		if (!is_number(input) || input.length() > 1){
			this->search_print();
			std::cout << "Input must contain a single digit!" << std::endl;
			continue;
		}

		slot = input[0] - '0';
		if (slot == 0 ){
			this->search_print();
			std::cout << "Duh!! There is no contact 0!!" << std::endl;
			continue;
		}
		if (slot > 8){
			this->search_print();
			std::cout << "Phonebook only has room for 8 contacts!" << std::endl;
			continue;
		}

		if (this->_get_nbr_contacts() == 0 || slot > this->_get_nbr_contacts()){
			this->search_print();
			std::cout << "Contact '" << input << "' is still empty" << std::endl;
			continue;
		}

		slot -= 1;
		while (1){
			this->search_draw();
			std::cout << "\033[1;36mFirst name: \033[0m" << this->_contacts[slot].getFirstName() << std::endl;
			std::cout << "\033[1;36mLast name: \033[0m" << this->_contacts[slot].getLastName() << std::endl;
			std::cout << "\033[1;36mNickname: \033[0m" << this->_contacts[slot].getNickName() << std::endl;
			std::cout << "\033[1;36mPhone number: \033[0m" << this->_contacts[slot].getPhoneNumber() << std::endl;
			std::cout << "\033[1;36mDarkeste secret: \033[0m" << this->_contacts[slot].getDarkestSecret() << std::endl;
			std::cout << "\033[1;36mType \033[1;31mBACK\033[1;36m to return:\033[0m";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return (this->eof_input(), 1);
			if (input == "BACK")
				return (0);
		}
		
	}
	return (0);
}

void	PhoneBook::add_draw(void) const{

	std::system("clear");
	std::cout << "\033[1;33m" << std::endl;
	std::cout << "===================================================================================================" << std::endl;
	std::cout << "          █████\033[1;36m╗ \033[1;33m███████\033[1;36m╗ \033[1;33m███████\033[1;36m╗      " << std::endl;
	std::cout << "         \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m╗ \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m╗ \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m╗     " << std::endl;
	std::cout << "         \033[1;33m███████\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║     " << std::endl;
	std::cout << "         \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║     " << std::endl;
	std::cout << "         \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║\033[1;33m███████\033[1;36m╔╝\033[1;33m███████\033[1;36m╔╝     " << std::endl;
	std::cout << "         \033[1;36m╚═╝  ╚═╝╚══════╝ ╚══════╝      " << std::endl;
	std::cout << "\033[1;33m===================================================================================================\033[0m" << std::endl;
	return;
}

int	PhoneBook::add_menu(void){

	std::string	input;
	std::string	fields[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	std::string	values[5];
	int			i;

	for (i = 0; i < 5; i++)
	{
		this->add_draw();
		while (1)
		{
			if (this->_get_nbr_contacts() == 8)
				std::cout << std::endl << "Entering " << 8 << "# contact" << std::endl;
			else
				std::cout << std::endl << "Entering " << this->_get_nbr_contacts() + 1 << "# contact" << std::endl;
			std::cout << "\033[1;33m" << fields[i] << "\033[0m";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return (this->eof_input(), 1);

			if (input.empty()){
				this->add_draw();
				std::cout << "Field cannot be empty!" << std::endl;
				continue;
			}

			if (i == 3 && !is_number(input)){
				this->add_draw();
				std::cout << "Phone number must contain only numbers!" << std::endl;
				continue;
			}

			values[i] = input;
			break;
		}
	}

	i = this->_get_nbr_contacts();
	if (i == 8)
		i = 7;
	this->_contacts[i].setFirstName(values[0]);
	this->_contacts[i].setLastName(values[1]);
	this->_contacts[i].setNickName(values[2]);
	this->_contacts[i].setPhoneNumber(values[3]);
	this->_contacts[i].setDarkestSecret(values[4]);
	this->_add_nbr_contacts();

	return (0);

}

void	PhoneBook::start_draw(void) const{

	std::system("clear");
	std::cout << "\033[1;34m                         ***** ddiogo-f presents *****" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "\033[1;34m██████\033[1;33m╗ \033[1;34m██\033[1;33m╗  \033[1;34m██\033[1;33m╗ \033[1;34m██████\033[1;33m╗ \033[1;34m███\033[1;33m╗   \033[1;34m██\033[1;33m╗\033[1;34m███████\033[1;33m╗\033[1;34m██████\033[1;33m╗  \033[1;34m██████\033[1;33m╗  \033[1;34m██████\033[1;33m╗ \033[1;34m██\033[1;33m╗  \033[1;34m██\033[1;33m╗" << std::endl;
	std::cout << "\033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m████\033[1;33m╗  \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔════╝\033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║ \033[1;34m██\033[1;33m╔╝" << std::endl;
	std::cout << "\033[1;34m██████\033[1;33m╔╝\033[1;34m███████\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔\033[1;34m██\033[1;33m╗ \033[1;34m██\033[1;33m║\033[1;34m█████\033[1;33m╗  \033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m█████\033[1;33m╔╝ " << std::endl;
	std::cout << "\033[1;34m██\033[1;33m╔═══╝ \033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║╚\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔══╝  \033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔═\033[1;34m██\033[1;33m╗ " << std::endl;
	std::cout << "\033[1;34m██\033[1;33m║     \033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m║╚\033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║ ╚\033[1;34m████\033[1;33m║\033[1;34m███████\033[1;33m╗\033[1;34m███████\033[1;33m║╚\033[1;34m██████\033[1;33m╔╝╚\033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m╗\033[1;34m" << std::endl;
	std::cout << "\033[1;33m╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\033[1;34m" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "                       ***** A 42 Lisboa Project *****\033[0m" << std::endl;
	std::cout << "Commands: \033[1;33mADD\033[0m | \033[1;36mSEARCH\033[0m | \033[1;31mEXIT\033[0m\n" << std::endl;
	std::cout << "Input command!! : ";

}

int	PhoneBook::start_menu(){

	std::string	line;

	this->start_draw();
	std::getline(std::cin, line);
	if (std::cin.eof())
	{
		this->eof_input();
		return (1);
	}
	else
		return (this->start_input(line));

	return (0);
}

int	PhoneBook::start_input(std::string line){

	if (line == "ADD")
	{
		return (this->add_menu());
	}
	else if (line == "SEARCH")
	{
		return (this->search_menu());
	}
	else if (line == "EXIT")
	{
		this->eof_input();
		return (1);
	}
	else
	{
		this->start_menu();
		std::cout << "\033[1;36mI have no idea what you want!\033[0m\n" << std::endl;
		return (0);
	}
	return (0);
}

void	PhoneBook::eof_input(void) const{
	std::system("clear");
	std::cout << "\033[1;35m====================================================================================================" << std::endl;
	std::cout << "     ██████\033[1;33m╗ \033[1;35m██\033[1;33m╗   \033[1;35m██\033[1;33m╗\033[1;35m███████\033[1;33m╗     \033[1;35m██████\033[1;33m╗ \033[1;35m██\033[1;33m╗   \033[1;35m██\033[1;33m╗\033[1;35m███████\033[1;33m╗  \033[1;35m██\033[1;33m╗  \033[1;35m██\033[1;33m╗" << std::endl;;
	std::cout << "     \033[1;35m██\033[1;33m╔══\033[1;35m██\033[1;33m╗ \033[1;35m██\033[1;33m╗ \033[1;35m██\033[1;33m╔╝\033[1;35m██\033[1;33m╔════╝     \033[1;35m██\033[1;33m╔══\033[1;35m██\033[1;33m╗ \033[1;35m██\033[1;33m╗ \033[1;35m██\033[1;33m╔╝\033[1;35m██\033[1;33m╔════╝  \033[1;35m██\033[1;33m║  \033[1;35m██\033[1;33m║" << std::endl;;
	std::cout << "     \033[1;35m██████\033[1;33m═╝  \033[1;35m████\033[1;33m╔╝ \033[1;35m█████\033[1;33m╗       \033[1;35m██████\033[1;33m═╝  \033[1;35m████\033[1;33m╔╝ \033[1;35m█████\033[1;33m╗    \033[1;35m██\033[1;33m║  \033[1;35m██\033[1;33m║" << std::endl;;
	std::cout << "     \033[1;35m██\033[1;33m╔══\033[1;35m██\033[1;33m╗   \033[1;35m██\033[1;33m╔╝  \033[1;35m██\033[1;33m╔══╝       \033[1;35m██\033[1;33m╔══\033[1;35m██\033[1;33m╗   \033[1;35m██\033[1;33m╔╝  \033[1;35m██\033[1;33m╔══╝    ╚═╝  ╚═╝" << std::endl;;
	std::cout << "     \033[1;35m██████\033[1;33m╔╝   \033[1;35m██\033[1;33m║   \033[1;35m███████\033[1;33m╗     \033[1;35m██████\033[1;33m╔╝   \033[1;35m██\033[1;33m║   \033[1;35m███████\033[1;33m╗  \033[1;35m██\033[1;33m╗  \033[1;35m██\033[1;33m╗" << std::endl;;
	std::cout << "     \033[1;33m╚═════╝    ╚═╝   ╚══════╝     ╚═════╝    ╚═╝   ╚══════╝  ╚═╝  ╚═╝" << std::endl;;
	std::cout << "\033[1;35m====================================================================================================\033[0m" << std::endl;
	return;
}

void	PhoneBook::_add_nbr_contacts(){
	if (_nbr_contacts < 8){
		_nbr_contacts++;
	}
	return;
}

int		PhoneBook::_get_nbr_contacts() const{
	return (_nbr_contacts);
}
