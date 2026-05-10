#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon{

	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string &getType() const;
		void	setType(const std::string newType);

	private:
		std::string	_type;

};


#endif