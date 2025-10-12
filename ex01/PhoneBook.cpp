#include "PhoneBook.hpp"
#include <iostream>
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


void	PhoneBook::search_draw(void) const{

	system("clear");
	std::cout << "\033[1;36m                                                                                        " << std::endl;
	std::cout << "===================================================================================================" << std::endl;
	std::cout << "          ███████\033[1;31m╗\033[1;36m███████\033[1;31m╗ \033[1;36m█████\033[1;31m╗ \033[1;36m██████\033[1;31m╗  \033[1;36m██████\033[1;31m╗\033[1;36m██\033[1;31m╗  \033[1;36m██\033[1;31m╗     " << std::endl;
	std::cout << "          \033[1;36m██\033[1;31m╔════╝\033[1;36m██\033[1;31m╔════╝\033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m╗\033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m╗\033[1;36m██\033[1;31m╔════╝\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;36m███████\033[1;31m╗\033[1;36m█████\033[1;31m╗  \033[1;36m███████\033[1;31m║\033[1;36m██████\033[1;31m═╣\033[1;36m██\033[1;31m║     \033[1;36m███████\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;31m╚════\033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m╔══╝  \033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m║     \033[1;36m██\033[1;31m╔══\033[1;36m██\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;36m███████\033[1;31m║\033[1;36m███████\033[1;31m╗\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║╚\033[1;36m██████\033[1;31m╗\033[1;36m██\033[1;31m║  \033[1;36m██\033[1;31m║     " << std::endl;
	std::cout << "          \033[1;31m╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝     " << std::endl;
	std::cout << "\033[1;36m===================================================================================================" << std::endl;
	return;
}

int		PhoneBook::search_menu(void) const{

	std::string	input;
	int			slot;

	while (1)
	{
		if (!std::getline(std::cin, input))
			return (eof_input(), 1);

		if (input.empty()){
			search_draw();
			std::cout << "Input cannot be empty!" << std::endl;
			continue;
		}

		if (!is_number(input) || input.length() > 1){
			search_draw();
			std::cout << "Input may only contain 1 digit!" << std::endl;
			continue;
		}

		slot = input[0] - '0';
		if (slot == 0 ){
			search_draw();
			std::cout << "Duh!! There is no contact 0!!" << std::endl;
			continue;
		}

		if (slot > 8){
			search_draw();
			std::cout << "Phonebook only has room for 8 contacts!" << std::endl;
			continue;
		}

		if (slot < _get_nbr_contacts()){
			search_draw();
			std::cout << "Contact '" << input << "' is still empty" << std::endl;
			continue;
		}

		
	}
	return (0);
}

void	PhoneBook::add_draw(void) const{

	system("clear");
	std::cout << "\033[1;33m" << std::endl;
	std::cout << "===================================================================================================" << std::endl;
	std::cout << "          █████\033[1;36m╗ \033[1;33m███████\033[1;36m╗ \033[1;33m███████\033[1;36m╗      " << std::endl;
	std::cout << "         \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m╗ \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m╗ \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m╗     " << std::endl;
	std::cout << "         \033[1;33m███████\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║     " << std::endl;
	std::cout << "         \033[1;33m██\033[1;36m╔══\033[1;33m██\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║ \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║     " << std::endl;
	std::cout << "         \033[1;33m██\033[1;36m║  \033[1;33m██\033[1;36m║\033[1;33m███████\033[1;36m╔╝\033[1;33m███████\033[1;36m╔╝     " << std::endl;
	std::cout << "         \033[1;36m╚═╝  ╚═╝╚══════╝ ╚══════╝      " << std::endl;
	std::cout << "\033[1;33m===================================================================================================" << std::endl;
	return;
}

int	PhoneBook::add_menu(void){

	std::string	input;
	std::string	fields[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string	values[5];
	int			i;

	for (i = 0; i < 5; i++)
	{
		while (1)
		{
			add_draw();
			std::cout << fields[i] << ": ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return (eof_input(), 1);

			if (input.empty()){
				add_draw();
				std::cout << "Field cannot be empty!" << std::endl;
				continue;
			}

			if (i == 3 && !is_number(input)){
				add_draw();
				std::cout << "Phone number must contain only numbers!" << std::endl;
				continue;
			}

			values[i] = input;
			break;
		}
	}

	i = _get_nbr_contacts();
	_contacts[i].setFirstName(values[0]);
	_contacts[i].setLastName(values[1]);
	_contacts[i].setNickName(values[2]);
	_contacts[i].setPhoneNumber(values[3]);
	_contacts[i].setDarkestSecret(values[4]);
	_add_nbr_contacts();

	return (0);

}

void	PhoneBook::start_draw(void) const{

	system("clear");
	std::cout << "\033[1;34m                         ***** ddiogo-f presents *****" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "\033[1;34m██████\033[1;33m╗ \033[1;34m██\033[1;33m╗  \033[1;34m██\033[1;33m╗ \033[1;34m██████\033[1;33m╗ \033[1;34m███\033[1;33m╗   \033[1;34m██\033[1;33m╗\033[1;34m███████\033[1;33m╗\033[1;34m██████\033[1;33m╗  \033[1;34m██████\033[1;33m╗  \033[1;34m██████\033[1;33m╗ \033[1;34m██\033[1;33m╗  \033[1;34m██\033[1;33m╗" << std::endl;
	std::cout << "\033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m████\033[1;33m╗  \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔════╝\033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║ \033[1;34m██\033[1;33m╔╝" << std::endl;
	std::cout << "\033[1;34m██████\033[1;33m╔╝\033[1;34m███████\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔\033[1;34m██\033[1;33m╗ \033[1;34m██\033[1;33m║\033[1;34m█████\033[1;33m╗  \033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m█████\033[1;33m╔╝ " << std::endl;
	std::cout << "\033[1;34m██\033[1;33m║═══╝ \033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║╚\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔══╝  \033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔═\033[1;34m██\033[1;33m╗ " << std::endl;
	std::cout << "\033[1;34m██\033[1;33m║     \033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m║╚\033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║ ╚\033[1;34m████\033[1;33m║\033[1;34m███████\033[1;33m╗\033[1;34m███████\033[1;33m║╚\033[1;34m██████\033[1;33m╔╝╚\033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m╗\033[1;34m" << std::endl;
	std::cout << "\033[1;33m╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\033[1;34m" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "                       ***** A 42 Lisboa Project *****\033[0m" << std::endl;
	std::cout << "Commands: \033[1;33mADD\033[0m | \033[1;36mSEARCH\033[0m | \033[1;31mEXIT\033[0m\n" << std::endl;
	std::cout << "Input command!! : ";

}

int	PhoneBook::start_menu(){

	std::string	line;

	start_draw();
	std::getline(std::cin, line);
	if (std::cin.eof())
	{
		eof_input();
		return (1);
	}
	else
		return (start_input(&line));

	return (0);
}

int	PhoneBook::start_input(std::string *line){

	if (*line == "ADD")
	{
		//add_draw();
		return (add_menu());
	}
	else if (*line == "SEARCH")
	{
		//search_draw();
		return (search_menu());
	}
	else if (*line == "EXIT")
		return (std::cout << "\033[1;31mYou typed EXIT\033[0m" << std::endl, 1);
	else
	{
		start_menu();
		std::cout << "\033[1;36mI have no idea what you want!\033[0m\n" << std::endl;
		return (0);
	}
	return (0);
}

void	PhoneBook::eof_input(void) const{
	system("clear");
	std::cout << "\033[0m\nYou asked to leave..." << std::endl;
	return;
}

void	PhoneBook::_add_nbr_contacts(){
	if (this->_nbr_contacts < 7){
		this->_nbr_contacts++;
	}
	return;
}

int		PhoneBook::_get_nbr_contacts() const{
	return (_nbr_contacts);
}

bool	PhoneBook::is_number(const std::string line) const{
	for (int i = 0; i < line.length(); i++){
		if (!std::isdigit(line[i]))
			return (false);
	}
	return (true);
}