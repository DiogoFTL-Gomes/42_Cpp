#include <iostream>
#include "c_comparison.hpp"

void	checkit(C_comparison *one, C_comparison *two)
{
	if (one == two)
		std::cout << one->letter << " is physically the same as " << two->letter << std::endl;
	else
		std::cout << one->letter << " is not the same physically as " << two->letter << std::endl;

}

int	main(void)
{
	C_comparison	example1(42, 'a');// Fun fact: O char é publico logo, no construtor, tem que ser passado o valor antes do inteiro privado
	C_comparison	example2(42, 'b');
	C_comparison	example3(-42, 'c');

	checkit(&example1, &example1);
	checkit(&example1, &example2);
	checkit(&example2, &example3);
	example1.compare(&example2);
	example1.compare(&example3);
	example2.compare(&example3);
	example3.compare(&example1);
}
