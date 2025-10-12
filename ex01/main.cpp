#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;

	while (true)
	{
		phonebook.start_draw();
		if (phonebook.start_menu() == 1)
			break;
	}

	return (0);
}
