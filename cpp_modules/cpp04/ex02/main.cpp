#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() 
{
    std::cout << GREEN << "----------====EXIRCISE====----------\n" << PURPLE << std::endl;
    {
        const int numAnimals = 10;
        AAnimal* animals[numAnimals];

        for (int i = 0; i < numAnimals; ++i) {
            if (i < numAnimals / 2) {
                animals[i] = new Dog();
            } else {
                animals[i] = new Cat();
            }
        }

        for (int i = 0; i < numAnimals; ++i) {
            std::cout << animals[i]->getType() << " makes sound: ";
            animals[i]->makeSound();
        }
        for (int i = 0; i < numAnimals; ++i) {
            delete animals[i];
        }
        return 0;
    }
}