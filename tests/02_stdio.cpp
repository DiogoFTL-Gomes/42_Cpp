#include <iostream>
#include <string.h>

int	main(void)
{
	std::string buff;

	std::cout << "Bom dia, mundo cruel!!" << std::endl;
	std::cout << "Diz uma palavra, meu!:";
	std::getline(std::cin, buff);
	std::cout << "Tu disseste: [" << buff << "]" << std::endl;
	return (0);
}