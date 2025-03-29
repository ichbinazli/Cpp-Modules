#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#define PURPLE "\033[38;5;92m"
#define GREEN "\033[38;5;41m"
#define CYAN    "\033[36m"
#define ORANGE "\033[38;5;208m"

# include <iostream>

class AAnimal
{
  protected:
	std::string _type;

  public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	void setType(const std::string type);
	const std::string getType(void) const;

	virtual void makeSound(void) const = 0;
};

#endif