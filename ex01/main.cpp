#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <csignal>

void	eof_input(void){
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

void	start_draw(void){
	std::system("clear");
	std::cout << "\033[1;34m                         ***** ddiogo-f presents *****" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "\033[1;34m██████\033[1;33m╗ \033[1;34m██\033[1;33m╗  \033[1;34m██\033[1;33m╗ \033[1;34m██████\033[1;33m╗ \033[1;34m███\033[1;33m╗   \033[1;34m██\033[1;33m╗\033[1;34m███████\033[1;33m╗\033[1;34m██████\033[1;33m╗  \033[1;34m██████\033[1;33m╗  \033[1;34m██████\033[1;33m╗ \033[1;34m██\033[1;33m╗  \033[1;34m██\033[1;33m╗" << std::endl;
	std::cout << "\033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m████\033[1;33m╗  \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔════╝\033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m╔═══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║ \033[1;34m██\033[1;33m╔╝" << std::endl;
	std::cout << "\033[1;34m██████\033[1;33m╔╝\033[1;34m███████\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔\033[1;34m██\033[1;33m╗ \033[1;34m██\033[1;33m║\033[1;34m█████\033[1;33m╗  \033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m█████\033[1;33m╔╝ " << std::endl;
	std::cout << "\033[1;34m██\033[1;33m╔═══╝ \033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║╚\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔══╝  \033[1;34m██\033[1;33m╔══\033[1;34m██\033[1;33m╗\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m║   \033[1;34m██\033[1;33m║\033[1;34m██\033[1;33m╔═\033[1;34m██\033[1;33m╗ " << std::endl;
	std::cout << "\033[1;34m██\033[1;33m║     \033[1;34m██\033[1;33m║  \033[1;34m██\033[1;33m║╚\033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║ ╚\033[1;34m████\033[1;33m║\033[1;34m███████\033[1;33m╗\033[1;34m███████\033[1;33m║╚\033[1;34m██████\033[1;33m╔╝╚\033[1;34m██████\033[1;33m╔╝\033[1;34m██\033[1;33m║ ╚\033[1;34m██\033[1;33m╗\033[1;34m" << std::endl;
	std::cout << "\033[1;33m╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\033[1;34m" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "                       ***** A 42 Lisboa Project *****\033[0m" << std::endl;
	std::cout << "Commands: \033[1;33mADD\033[0m | \033[1;36mSEARCH\033[0m | \033[1;31mEXIT\033[0m\n" << std::endl;
	std::cout << "Input command!! >> ";
}

void	add_draw(void){
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

void	search_draw(void){
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

std::string	formatField(std::string field){
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return (field);
}

bool	is_alnumsp(const std::string line){
	for (int i = 0; i < line.length(); i++){
		if (!std::isalnum(line[i]) && !std::isspace(line[i]))
			return (false);
	}
	return (true);
}

bool	is_number(const std::string line){
	for (int i = 0; i < line.length(); i++){
		if (!std::isdigit(line[i]))
			return (false);
	}
	return (true);
}

void	search_print(PhoneBook *phonebook){

	if (phonebook->get_nbr_contacts() == 0){
		search_draw();
		std::cout << "\033[0mPhoneBook has no contacts." << std::endl;
		std::cout << "Type \033[1;31mBACK\033[0m to return:";
	}
	else{
		search_draw();
		std::cout << "\033[1;31m |First name| Last name| Nickname | Phone nbr|DarkSecret|\033[0m" << std::endl;
		for (int i = 0; i < phonebook->get_nbr_contacts(); i++){
			std::cout << i + 1 << "\033[1;31m|\033[0m" << std::setw(10) << formatField(phonebook->get_contacts(i, FIRSTN));
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(phonebook->get_contacts(i, LASTN));
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(phonebook->get_contacts(i, NICKN));
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(phonebook->get_contacts(i, NUMBER));
			std::cout << "\033[1;31m|\033[0m" << std::setw(10) << formatField(phonebook->get_contacts(i, DARKS));
			std::cout << "\033[1;31m|\033[0m" << std::endl;
		}
		std::cout << "Type \033[1;36mcontact number\033[0m to display" << std::endl;
		std::cout << "Type \033[1;31mBACK\033[0m to return:";
	}

	return ;
}

int	search_menu(PhoneBook *phonebook){

	std::string	input;
	int			slot;

	search_print(phonebook);
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (eof_input(), 1);
		if (input.empty()){
			search_print(phonebook);
			std::cout << std::endl << "Input cannot be empty! >> ";
			continue;
		}
		if (input == "BACK"){
			break;
		}
		if (!is_number(input) || input.length() > 1){
			search_print(phonebook);
			std::cout << std::endl << "Input must contain a single digit! >> ";
			continue;
		}
		slot = input[0] - '0';
		if (slot == 0 ){
			search_print(phonebook);
			std::cout << std::endl << "Duh!! There is no contact 0!! >> ";
			continue;
		}
		if (slot > 8){
			search_print(phonebook);
			std::cout << std::endl << "Phonebook only has room for 8 contacts! >> ";
			continue;
		}
		if (phonebook->get_nbr_contacts() == 0 || slot > phonebook->get_nbr_contacts()){
			search_print(phonebook);
			std::cout << std::endl << "Contact '\033[1;36m" << input << "\033[0m' is still empty >> " ;
			continue;
		}
		slot -= 1;
		while (1){
			search_draw();
			std::cout << "\033[1;36mFirst name: \033[0m" << phonebook->get_contacts(slot, FIRSTN) << std::endl;
			std::cout << "\033[1;36mLast name: \033[0m" << phonebook->get_contacts(slot, LASTN) << std::endl;
			std::cout << "\033[1;36mNickname: \033[0m" << phonebook->get_contacts(slot, NICKN) << std::endl;
			std::cout << "\033[1;36mPhone number: \033[0m" << phonebook->get_contacts(slot, NUMBER) << std::endl;
			std::cout << "\033[1;36mDarkeste secret: \033[0m" << phonebook->get_contacts(slot, DARKS) << std::endl;
			std::cout << "\033[1;36mType \033[1;31mBACK\033[1;36m to return:\033[0m";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return (eof_input(), 1);
			if (input == "BACK"){
				search_print(phonebook);
				break;}
		}
	}
	return (0);
}

int	add_menu(PhoneBook *phonebook){

	std::string	input;
	std::string	fields[5] = {"First name >> ", "Last name >> ", "Nickname >> ", "Phone number >> ", "Darkest secret >> "};
	std::string	values[5];
	int			i;

	for (i = 0; i < 5; i++)
	{
		add_draw();
		while (1)
		{
			if (phonebook->get_nbr_contacts() == 8)
				std::cout << std::endl << "Entering " << 8 << "# contact" << std::endl;
			else
				std::cout << std::endl << "Entering " << phonebook->get_nbr_contacts() + 1 << "# contact" << std::endl;
			std::cout << "\033[1;33m" << fields[i] << "\033[0m";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return (eof_input(), 1);

			if (input.empty()){
				add_draw();
				std::cout << "Field cannot be empty!" << std::endl;
				continue;
			}

			if (i != 3 && !is_alnumsp(input)){
				add_draw();
				std::cout << "This field must not have special characters!" << std::endl;
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

	i = phonebook->get_nbr_contacts();
	if (i == 8)
		i = 7;
	phonebook->set_contacts(values, i);
	return (0);

}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	std::signal(SIGINT, SIG_IGN);
	start_draw();
	while (true)
	{
		std::getline(std::cin, line);
		if (std::cin.eof() || line == "EXIT"){
			eof_input();
			return (1);
		}
		else
		if (line == "ADD"){
			if (add_menu(&phonebook))
				return (1);
			start_draw();
			continue;
		}
		else if (line == "SEARCH"){
			if (search_menu(&phonebook) == 1)
				return (1);
			start_draw();
			continue;
		}
		else{
			start_draw();
			std::cout << std::endl << "\033[1;36mI have no idea what you want!\033[0m >> ";
			continue ;
		}
	}

	return (0);
}
