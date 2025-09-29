#include <stdio.h>

int	gl_var = 1;

int	f(int a)
{
	return a;
}

namespace Foo
{
	int	gl_var = ::gl_var + 3;
	int	f(int a)
	{
		return a + 1;
	}
}

namespace Bar
{
	int	gl_var = ::gl_var + 5;
	int	f(int a)
	{
		return a * 2;
	}
}

namespace Muf = Bar;

int	main(void)
{
	int x = 5;

	printf("gl_var:		[%d]\n", gl_var);
	printf("f():		[%d]\n\n", f(x));

	printf("Foo::gl_var	[%d]\n", Foo::gl_var);
	printf("Foo::f():	[%d]\n\n", Foo::f(x));

	printf("Bar::gl_var	[%d]\n", Bar::gl_var);
	printf("Bar::f():	[%d]\n\n", Bar::f(x));

	printf("Muf::gl_var	[%d]\n", Muf::gl_var);
	printf("Muf::f():	[%d]\n\n", Muf::f(x));

	printf("::gl_var	[%d]\n", ::gl_var);
	printf("::f():		[%d]\n\n", ::f(x));

	return 0;
}