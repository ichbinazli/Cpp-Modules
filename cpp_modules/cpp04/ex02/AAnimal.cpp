#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "Default constructor - (Animal)" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << "Copy constructor - (Animal)" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor - (Animal)" << CYAN << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Assignation operator - (Animal)" << std::endl;
	return (*this);
}

void AAnimal::setType(const std::string type)
{
	this->_type = type;
}

const std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void AAnimal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
