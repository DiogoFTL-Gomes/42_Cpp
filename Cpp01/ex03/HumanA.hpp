#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon &theWeapon);
		~HumanA();

		void	attack() const;
		std::string	getHumanName() const;

	private:
		std::string	_name;
		Weapon		&_theWeapon;
};


#endif
