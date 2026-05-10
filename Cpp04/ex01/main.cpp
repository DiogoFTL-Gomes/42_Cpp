#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\e[1;100m=== Direct Animal Test (Allowed in ex01) ===\033[0m" << std::endl;
	{
		Animal basic;
		std::cout << "Type: " << basic.getType() << std::endl;
		basic.makeSound(); // Deve mostrar um som genérico
		basic.addIdea("Prrrrr");
		basic.rememberIdea(0);
	}
	std::cout << std::endl;

	std::cout << "\e[1;100m=== Basic Construction and Polymorphism ===\033[0m" << std::endl;
	{
		const Animal *philo = new Dog();
		std::cout << std::endl;
		const Animal *ignis = new Cat();
		std::cout << std::endl;

		std::cout << "Philo is a " << philo->getType() << std::endl;
		std::cout << "Ignis is a " << ignis->getType() << std::endl;
		std::cout << std::endl;

		philo->makeSound();
		ignis->makeSound();
		std::cout << std::endl;

		delete philo;
		std::cout << std::endl;
		delete ignis;
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Array of Animals ===\033[0m" << std::endl;
	{
		int beds = 4;
		Animal *animalShelter[beds];
		for (int i = 0; i < beds; ++i)
			animalShelter[i] = (i % 2 == 0) ? (Animal *)new Dog() : (Animal *)new Cat();

		std::cout << std::endl;
		for (int i = 0; i < beds; ++i)
		{
			std::cout << "[" << i << "] " << animalShelter[i]->getType() << " makes: ";
			animalShelter[i]->makeSound();
		}

		std::cout << "\n--- Rawdog copy ---" << std::endl;
		Animal* rawDog = new Dog(*(Dog*)animalShelter[1]);//undefined behaviour
		rawDog->makeSound();
		delete rawDog;
		std::cout << "\n--- safe clone() ---" << std::endl;
		Animal* safeCopy = animalShelter[1]->clone();
		safeCopy->makeSound();
		delete safeCopy;
		std::cout << std::endl;

		for (int i = 0; i < beds; ++i)
			delete animalShelter[i];
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Deep Copy Test ===\033[0m" << std::endl;
	{
		Dog *original = new Dog();
		original->addIdea("Eat bacon");
		original->addIdea("Chase cat");
		std::cout << "Original Dog's first idea: " << original->rememberIdea(0) << std::endl;
		std::cout << "Original Dog's second idea: " << original->rememberIdea(1) << std::endl;
		std::cout << std::endl;

		std::cout << "Copy constructing another Dog..." << std::endl;
		Dog *copyDog = original->clone();
		std::cout << "CopyDog's first idea: " << copyDog->rememberIdea(0) << std::endl;
		std::cout << "CopyDog's second idea: " << copyDog->rememberIdea(1) << std::endl;

		std::cout << "\nAdding idea to original Dog's..." << std::endl;
		original->addIdea("Sleep all day");
		std::cout << "Original now thinks: " << original->rememberIdea(2) << std::endl;
		std::cout << "CopyDog still thinks: " << copyDog->rememberIdea(2) << std::endl;

		std::cout << std::endl;
		delete (original);
		std::cout << std::endl;
		delete (copyDog);
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== All tests done ===\033[0m" << std::endl;
	return 0;
}


/*int	main(){
	int	beds = 4;

	const Animal	*philo = new Dog();
	std::cout << std::endl;
	const Animal	*ignis = new Cat();
	std::cout << std::endl;

	Animal	*animalShelter[beds];
	for (int i = 0; i < beds; i++){
		if (i % 2 == 0){
			animalShelter[i] = new Dog();
		}
		else{
			animalShelter[i] = new Cat();
		}
	}
	std::cout << std::endl;

	animalShelter[0]->addIdea("Play ball!!");
	animalShelter[1]->addIdea("Eat fish....");
	animalShelter[2]->addIdea("Catch squirrel!!!");
	animalShelter[3]->addIdea("Destroy all humans!!");
	std::cout << std::endl;

	std::cout << "\"" << animalShelter[0]->rememberIdea(0) << "\" thinks the " << animalShelter[0]->getType() << std::endl;
	std::cout << "\"" << animalShelter[0]->rememberIdea(1) << "\" thinks the " << animalShelter[0]->getType() << std::endl;
	std::cout << std::endl;
	std::cout <<  "\"" << animalShelter[1]->rememberIdea(0) << "\" thinks the " << animalShelter[1]->getType() << std::endl;
	std::cout << std::endl;
	std::cout <<  "\"" << animalShelter[2]->rememberIdea(0) << "\" thinks the " << animalShelter[2]->getType() << std::endl;
	std::cout << std::endl;
	std::cout <<  "\"" << animalShelter[3]->rememberIdea(0) << "\" thinks the " << animalShelter[3]->getType() << std::endl;
	std::cout << std::endl;

	delete (philo);
	philo = animalShelter[0]->clone();
	philo->makeSound();
	std::cout << "\"" << philo->rememberIdea(0) << "\" thinks philo the " << philo->getType() << std::endl;
	std::cout << std::endl;

	
	delete (ignis);
	ignis = animalShelter[1]->clone();
	ignis->makeSound();
	std::cout << "\"" << ignis->rememberIdea(0) << "\" thinks ignis the " << ignis->getType() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < beds; i++){
		delete animalShelter[i];
	}
	std::cout << std::endl;
	std::cout << "\"" << philo->rememberIdea(0) << "\" thinks the philo the " << philo->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "\"" << ignis->rememberIdea(0) << "\" thinks the ignis the " << ignis->getType() << std::endl;
	std::cout << std::endl;

	delete (philo);
	delete (ignis);
	return (0);
}*/