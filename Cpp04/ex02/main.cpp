#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\e[1;100m=== Abstract Class Test ===\033[0m" << std::endl;
	{
		// AAnimal test; // abstract class cannot be instaciated
		const AAnimal *dog = new Dog();
		std::cout << std::endl;
		const AAnimal *cat = new Cat();

		std::cout << "\nAAnimal type: " << dog->getType() << std::endl;
		std::cout << "AAnimal type: " << cat->getType() << std::endl;

		std::cout << "\nDog makes sound: ";
		dog->makeSound();
		std::cout << "Cat makes sound: ";
		cat->makeSound();

		std::cout << "\nDestroying Dog and Cat:" << std::endl;
		delete dog;
		std::cout << std::endl;
		delete cat;
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Array of Abstract Animals (Polymorphism) ===\033[0m" << std::endl;
	{
		const int beds = 4;
		AAnimal *animalShelter[beds];

		for (int i = 0; i < beds; ++i)
		{
			if (i % 2 == 0)
				animalShelter[i] = new Dog();
			else
				animalShelter[i] = new Cat();
		}

		std::cout << std::endl;
		for (int i = 0; i < beds; ++i)
		{
			std::cout << "[" << i << "] "
					  << animalShelter[i]->getType()
					  << " makes: ";
			animalShelter[i]->makeSound();
		}

		std::cout << std::endl;
		for (int i = 0; i < beds; ++i)
			delete animalShelter[i];
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Brain Test (Ideas and Memory) ===\033[0m" << std::endl;
	{
		AAnimal *dog = new Dog();
		AAnimal *cat = new Cat();

		dog->addIdea("Chase the mailman");
		dog->addIdea("Eat bacon");
		cat->addIdea("Sleep on the keyboard");
		cat->addIdea("Conquer the world");

		std::cout << "\nDog first idea: " << dog->rememberIdea(0) << std::endl;
		std::cout << "Dog second idea: " << dog->rememberIdea(1) << std::endl;
		std::cout << "Cat first idea: " << cat->rememberIdea(0) << std::endl;
		std::cout << "Cat second idea: " << cat->rememberIdea(1) << std::endl;

		delete dog;
		delete cat;
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Polymorphic Clone Test ===\033[0m" << std::endl;
	{
		AAnimal *originalDog = new Dog();
		originalDog->addIdea("Bark at the moon");
		originalDog->addIdea("Dig holes");
		std::cout << std::endl;
	
		AAnimal *cloneDog = originalDog->clone();
		std::cout << std::endl;

		std::cout << "Original Dog first idea: " << originalDog->rememberIdea(0) << std::endl;
		std::cout << "Clone Dog first idea: " << cloneDog->rememberIdea(0) << std::endl;

		std::cout << "\nAdding new idea to original..." << std::endl;
		originalDog->addIdea("Chew slippers");

		std::cout << "Original Dog new idea: " << originalDog->rememberIdea(2) << std::endl;
		std::cout << "Clone Dog new idea: " << cloneDog->rememberIdea(2) << std::endl;

		std::cout << std::endl;
		delete originalDog;
		std::cout << std::endl;
		delete cloneDog;
	}

	std::cout << std::endl;
	std::cout << "\e[1;100m=== Abstract Animal Tests Completed ===\033[0m" << std::endl;
	return 0;
}


/*int	main(){
	//AAnimal test; // cannot declare object of abstract type

	int	beds = 4;

	const AAnimal	*philo = new Dog();
	std::cout << std::endl;
	const AAnimal	*ignis = new Cat();
	std::cout << std::endl;

	AAnimal	*animalShelter[beds];
	for (int i = 0; i < beds; i++){
		if (i % 2 == 0){
			animalShelter[i] = new Dog();
		}
		else{
			animalShelter[i] = new Cat();
		}
	}
	std::cout << std::endl;

	animalShelter[0]->addIdea("Play 2 ball!!");
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
	std::cout << "\"" << ignis->rememberIdea(0) << "\" thinks the philo the " << ignis->getType() << std::endl;
	std::cout << std::endl;

	delete (philo);
	delete (ignis);
	return (0);
}*/