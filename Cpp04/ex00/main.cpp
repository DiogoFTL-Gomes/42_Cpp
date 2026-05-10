#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\e[1;100m=== Basic Animal Tests ===\033[0m" << std::endl;
	{
		Animal temp;
		std::cout << "Type: " << temp.getType() << std::endl;
		temp.makeSound();
	}
	std::cout << std::endl;

	std::cout << "=== Polymorphic Behavior ===" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* philo = new Dog();
		const Animal* ignis = new Cat();

		std::cout << std::endl;
		std::cout << "Philo is a " << philo->getType() << " that sniffs your butt." << std::endl;
		std::cout << "Ignis is a " << ignis->getType() << " that coughs a furball." << std::endl;
		std::cout << "Meta is a " << meta->getType() << " that oozes pus. Disgusting!" << std::endl;

		std::cout << std::endl;
		philo->makeSound();
		ignis->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		delete meta;
		delete philo;
		delete ignis;
	}
	std::cout << std::endl;

	std::cout << "\e[1;100m=== WrongAnimal (No virtual) ===\e[0m" << std::endl;
	{
		const WrongAnimal* atem = new WrongAnimal();
		const WrongAnimal* singi = new WrongCat();

		std::cout << std::endl;
		std::cout << "Atem is a " << atem->getType() << " that has 20 eyes, scales and 3 mouths." << std::endl;
		std::cout << "Singi is a " << singi->getType() << "?? Is that even a thing?" << std::endl;
		std::cout << std::endl;

		atem->makeSound();  // WrongAnimal sound
		singi->makeSound(); // Still WrongAnimal sound! no virtual!

		std::cout << std::endl;
		std::cout << "Destroying WrongAnimals:" << std::endl;
		delete atem;
		delete singi;
	}
	std::cout << std::endl;

	std::cout << "\e[1;100m=== Copy and Assignment Tests ===\e[0m" << std::endl;
	{
		Dog rex;
		rex.makeSound();

		std::cout << "\nCreating copy of Rex..." << std::endl;
		Dog copyDog(rex);
		copyDog.makeSound();

		std::cout << "\nAssigning copyDog to a new Dog named Max..." << std::endl;
		Dog max;
		max = copyDog;
		max.makeSound();
	}
	std::cout << std::endl;

	std::cout << "\e[1;100m=== Polymorphic Destruction Test ===\e[0m" << std::endl;
	{
		const Animal* bobby = new Dog();
		bobby->makeSound();
		std::cout << "Deleting via Animal pointer:" << std::endl;
		delete bobby;
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== All tests done ===\033[0m" << std::endl;
	return 0;
}
