#include <string>
#include <iostream>

int	main(int argc, char *argv[])
{
	std::string	word;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		word = argv[i];
		for (int j = 0; j < (int)word.size(); j++)
		{
			std::cout << (char)std::toupper(word[j]);
		}
	}
	std::cout << std::endl;
	return (0);
}