#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default constructor - (Animal)" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Copy constructor - (Animal)" << std::endl;
}

Animal::~Animal()
{
	std::cout << CYAN << "Destructor - (Animal)" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Assignation operator - (Animal)" << std::endl;
	return (*this);
}

void Animal::setType(const std::string type)
{
	this->_type = type;
}

const std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
