#ifndef ANIMAL_HPP

# define ANIMAL_HPP

#define PURPLE "\033[38;5;92m"
#define YELLOW "\033[1;33m"
#define BLUE "\x1b[34;01m"

# include <iostream>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	void setType(const std::string type);
	const std::string getType(void) const;

	virtual void makeSound(void) const;
};

#endif