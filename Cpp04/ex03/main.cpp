#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter	*bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
/*int	main(){
	std::cout << "\n\e[1;35m###	On the planes of Ceep'lusplush, the gods made 2 warriors...	###\e[0m" << std::endl;

	ICharacter *bill = new Character("Bill");
	ICharacter *ted = new Character("Ted");

	std::cout << "\n\e[1;35m###	Using sacred knowledge a warrior created the means to protect 	###\e[0m" << std::endl;

	IMateriaSource	*spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());

	std::cout << "\n\e[1;35m###	With this new power, one warrior quickly filled is stock	###\e[0m" << std::endl;

	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("cure"));
	bill->unequip(3);
	bill->equip(spellBook->createMateria("cure"));
	ted->equip(spellBook->createMateria("ice"));
	ted->equip(spellBook->createMateria("ice"));
	ted->equip(spellBook->createMateria("cure"));
	ted->equip(spellBook->createMateria("cure"));

	std::cout << "\n\e[1;35m###	But one of them wanted to be the only one with power...	###\e[0m" << std::endl;

	bill->use(0, *ted);
	bill->use(0, *ted);
	bill->use(1, *ted);
	ted->use(3, *ted);
	bill->use("ice", *ted);
	ted->use("ice", *bill);
	bill->use("fire", *ted);
	ted->use("cure", *ted);
	bill->use("toads", *ted);
	ted->use(1, *bill);
	bill->use("itchy butt crack", *ted);

	std::cout << "\n\e[1;35m###	Delighted by their fight, the gods copied them...	###\e[0m" << std::endl;

	ICharacter *bubba = new Character(*(Character *)bill);
	bubba->equip(spellBook->createMateria("ice"));
	bill->use(0, *ted);
	bubba->use(0, *ted);

	Character toze(*(Character *)bubba);
	std::cout << toze.getName() << " likes his name. It's modern..." << std::endl;
	bubba->equip(spellBook->createMateria("ice"));
	bubba->equip(spellBook->createMateria("ice"));
	bubba->equip(spellBook->createMateria("ice"));
	bubba->equip(spellBook->createMateria("ice"));
	toze.equip(spellBook->createMateria("ice"));
	toze.equip(spellBook->createMateria("ice"));
	toze.equip(spellBook->createMateria("ice"));
	toze.equip(spellBook->createMateria("ice"));
	toze.equip(spellBook->createMateria("ice"));
	bubba->use(0, *ted);
	toze.use(0, *ted);
	bubba->use(1, *ted);
	toze.use(1, *ted);
	bubba->use(2, *ted);
	toze.use(2, *ted);
	bubba->use(3, *ted);
	toze.use(3, *ted);

	std::cout << "\n\e[1;35m###	Having grown bored, the gods eliminated them all...	###\e[0m" << std::endl;

	delete bubba;
	delete bill;
	delete ted;
	delete spellBook;
}*/

