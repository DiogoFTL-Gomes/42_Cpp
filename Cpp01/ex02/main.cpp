#include <iostream>

int	main(void){
	std::string	line = "HI THIS IS BRAIN";
	std::string	*stringPTR = &line;
	std::string	&stringREF = line;

	std::cout << &line << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl << std::endl;
	
	std::cout << line << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl << std::endl;
/*
	std::cout << "Changing line value:" << std::endl;
	line = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHH!!!!!!!!!!";
	std::cout << line << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << << std::endl << std::endl;

	std::cout << "Changing stringREF value:" << std::endl;
	stringREF = "Oh, its just a brain...";
	std::cout << line << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl << std::endl;
*/
	return (0);
}