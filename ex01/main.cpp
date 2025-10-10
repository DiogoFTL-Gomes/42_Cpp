#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	line = "Give me something to read!! : ";
	while (true)
	{
		std::cout << "\x1B[2J\x1B[30H";
		std::cout << line;
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << "\x1B[2J\x1B[30H";
			std::cout << "You asked to leave..." << std::endl;
			break;
		}
		else
		{
			line = line + " : ";
		}
	}

	return (0);
}
