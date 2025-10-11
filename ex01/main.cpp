#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;

	system("clear");
	phonebook.draw_start();
	while (true)
	{
		if (phonebook.start_menu() == 1)
			break;
	}

	return (0);
}
