#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){

	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon bigStick = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(bigStick);
	jim.attack();
	bigStick.setType("some other type of club");
	jim.attack();

	HumanB toze("Toze", club);
	toze.attack();
	club.setType("panela");
	toze.attack();

	return 0;
}