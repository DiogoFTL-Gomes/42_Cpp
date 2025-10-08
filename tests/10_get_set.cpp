#include <iostream>
#include "c_get_set.hpp"

int main(void)
{
	get_set	example;

	std::cout << "Val :" << example.getval() << std::endl;
	example.setval(42);
	std::cout << "Val modificada:" << example.getval() << std::endl;
	example.setval(-42);
	std::cout << "Val negativa:" << example.getval() << std::endl;

	return (0);
}