#include <iostream>
#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	uno("Garcia");
	std::cout << "\033[1;36mBuenos dias, mi nombre es \033[0m" << uno.getName() << std::endl;
	ClapTrap	dos(uno);
	std::cout << "\033[1;35mQué sorpresa! Yo también lo soy \033[0m" << dos.getName() << std::endl;

	ClapTrap	tres("Julio");
	std::cout << "\033[1;34mMuchachos!! Acaba de llegar el gran \033[0m" << tres.getName() << std::endl;
	dos = tres;
	std::cout << "\033[1;35mAh, yo también quería ser como \033[0m" << dos.getName() << "\033[1;35m pero no me conviene\033[0m" << std::endl;
	dos = ClapTrap("Manuel");
	std::cout << "\033[1;35mCreo que me veo mejor como \033[0m" << dos.getName() << std::endl;
	std::cout << uno.getName() << ", " << dos.getName() << " y " << tres.getName() << "! Los tres amigos!!" << std::endl;
	return 0;
}
