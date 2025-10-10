#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	system("clear");
	while (true)
	{
		phonebook.put_menu();
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			phonebook.eof_input();
			break;
		}
		else
			phonebook.check_input(line);
	}

	return (0);
}
