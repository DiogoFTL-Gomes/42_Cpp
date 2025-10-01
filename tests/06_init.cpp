#include "init1.hpp"
#include "init2.hpp"

int	main(void)
{
	//reparar que ordem de terminacao e inversa a ordem de inicializacao
	init1	test_a1('a', 42, 2.4f);
	init1	test_a2('b', 41, 2.3f);
	init1	test_a3('c', 40, 2.2f);
	init1	test_a4('d', 39, 2.1f);
	init1	test_a5('e', 38, 2.0f);
	init2	test_b1('z', 413, 3.14f);
	init2	test_b2('y', 414, 3.15f);
	init2	test_b3('x', 415, 3.16f);
	init2	test_b4('w', 416, 3.17f);
	init2	test_b5('v', 417, 3.18f);
	return (0);
}