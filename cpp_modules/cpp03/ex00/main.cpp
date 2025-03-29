#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap1("Clappy");
	clap1.displayStats();
	clap1.attack("Target1");
	clap1.displayStats();
	clap1.takeDamage(5);
	clap1.displayStats();
	clap1.beRepaired(3);
	clap1.displayStats();
	for (int i = 0; i < 10; ++i)
	{
		clap1.attack("Dummy Target");
	}
	clap1.displayStats();
	clap1.takeDamage(20);
	clap1.displayStats();
	std::cout << std::endl;
	clap1.beRepaired(5);
	clap1.displayStats();
	return (0);
}