#include "c_visibility.hpp"
#include <iostream>

int	main(void)
{
	C_visibility	example;

	example.publicint = 42;
	std::cout << "example.publicint = " << example.publicint << std::endl;
	//example._privateint = 42; //coisas declaradas como private não podem ser acedidas aqui.
	//std::cout << "example._privateint = " << example._privateint << std::endl;

	example.publicft();
	//example._privateft();//Nada disto vai compilar

	return (0);

}