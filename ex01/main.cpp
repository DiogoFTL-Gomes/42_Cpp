#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;

	while (true)
	{
		if (phonebook.start_menu() == 1)
			break;
	}

	return (0);
}
