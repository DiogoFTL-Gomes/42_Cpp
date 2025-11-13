#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(){
	std::cout << "\n\e[1;35m###	On the planes of Ceep'lusplush, the gods made 2 warriors...	###\e[0m" << std::endl;

	ICharacter *bill = new Character("Bill");
	ICharacter *ted = new Character("Ted");

	std::cout << "\n\e[1;35m###	Using sacred knowledge they created the means to protect themselves	###\e[0m" << std::endl;

	IMateriaSource	*spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());

	std::cout << "\n\e[1;35m###	With this new power, the warrior quickly filled their stock	###\e[0m" << std::endl;

	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("ice"));
	bill->equip(spellBook->createMateria("cure"));
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


	delete bill;
	delete ted;
	delete spellBook;
}

/*int main(void)
{
	std::cout << "\e[1;100m=== MateriaSource Learning Test ===\033[0m" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		std::cout << "Trying to create known Materias:" << std::endl;
		AMateria* tmp1 = src.createMateria("ice");
		AMateria* tmp2 = src.createMateria("cure");
		std::cout << "Created: " << tmp1->getType() << " and " << tmp2->getType() << std::endl;

		std::cout << "\nTrying to create unknown Materia:" << std::endl;
		AMateria* tmp3 = src.createMateria("fire");
		if (!tmp3)
			std::cout << "Unknown Materia type 'fire' — returned NULL ✅" << std::endl;

		delete tmp1;
		delete tmp2;
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Character Equip & Use Test ===\033[0m" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character me("me");
		Character bob("bob");

		AMateria* ice = src.createMateria("ice");
		AMateria* cure = src.createMateria("cure");

		me.equip(ice);
		me.equip(cure);
		me.use(0, bob);
		me.use(1, bob);
		me.use(2, bob); // invalid index, should do nothing
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Unequip Test (No Deletion) ===\033[0m" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		Character alice("Alice");
		AMateria* ice = src.createMateria("ice");

		alice.equip(ice);
		alice.unequip(0); // should not delete
		delete ice; // must delete manually (since unequip doesn’t)
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Deep Copy Test ===\033[0m" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Cure());

		Character original("Original");
		original.equip(src.createMateria("cure"));

		std::cout << "\nCopying character..." << std::endl;
		Character clone(original);

		std::cout << "\nOriginal uses materia:" << std::endl;
		original.use(0, clone);

		std::cout << "Clone uses materia (should be independent copy):" << std::endl;
		clone.use(0, original);
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== All Materia Tests Completed ===\033[0m" << std::endl;
	return 0;
}*/

/*int main()
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
}*/
