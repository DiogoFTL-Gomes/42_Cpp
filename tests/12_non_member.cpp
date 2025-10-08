#include <iostream>
#include "c_non_member.hpp"

void	f1(void)
{
	c_non_member	example;

	if (c_non_member::getnbrinst() < 5)
	{
		std::cout << "f1()Number of instances: " << c_non_member::getnbrinst() << std::endl;
		f1();;
	}
	std::cout << "f1()Number of instances: " << c_non_member::getnbrinst() << std::endl;
	return ;
}

int	main(void)
{
	std::cout << "Main()Number of starting instances: " << c_non_member::getnbrinst() << std::endl;
	f1();
	std::cout << "Main()Number of final instances: " << c_non_member::getnbrinst() << std::endl;
	return (0);
}
