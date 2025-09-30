#include <iostream>

int	main(void)
{
	char	buff[512];

	std::cout << "Bom dia, mundo cruel!!" << std::endl;
	std::cout << "Diz uma palavra, meu!:";
	std::cin >> buff;
	std::cout << "Tu disseste: [" << buff << "]" << std::endl;
	return (0);
}