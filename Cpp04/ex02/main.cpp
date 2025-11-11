#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(){
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
}