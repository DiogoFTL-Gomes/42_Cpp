#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(){
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	const Animal	*philo = new Dog();
	std::cout << std::endl;
	const Animal	*ignis = new Cat();
	std::cout << std::endl;

	std::cout << "Philo is a " << philo->getType() << " that sniffs your butt" << std::endl;
	std::cout << "Ignis is a " << ignis->getType() << " that coughs a furball" << std::endl;
	std::cout << "Meta is a " << meta->getType() << " that oozes pus. Discusting!" << std::endl;
	std::cout << std::endl;

	philo->makeSound();
	ignis->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	// WrongAnimal does not have a virtual function.
	const WrongAnimal	*atem = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal	*singi = new WrongCat();
	std::cout << std::endl;
	std::cout << "Atem is a " << atem->getType() << " that has 20 eyes, scales and 3 mouths. It's disturbing!" << std::endl;
	std::cout << "Singi is a " << singi->getType() << "?? Is that a thing? Heeww... " << std::endl;
	std::cout << std::endl;
	atem->makeSound();
	singi->makeSound();
	std::cout << std::endl;
	std::cout << "Destroying the WrongAnimals:" << std::endl;
	delete(atem);
	delete(singi);
	std::cout << std::endl;

	delete (philo);
	delete (ignis);
	delete (meta);
	return (0);
}