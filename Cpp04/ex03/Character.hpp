#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_inventory[4];

		void	_clearInventory();
		void	_copyInventory(Character const &other);

	public:
		Character(std::string const &name);
		Character(Character const &other);
		Character	&operator=(Character const &other);
		~Character();

		std::string const	&getName() const;
		void	equip(AMateria *m);
		void	unequip(int index);
		void	use(int index, ICharacter &target);
		void	use(std::string type, ICharacter &target);
};

#endif