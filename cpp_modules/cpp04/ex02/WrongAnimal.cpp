#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Default constructor called - (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "Copy constructor called - (WrongAnimal)" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called - (WrongAnimal)" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Assignation operator called - (WrongAnimal)" << std::endl;
	return (*this);
}

void WrongAnimal::setType(const std::string type)
{
	this->_type = type;
}

const std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

