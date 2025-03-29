#include "Base.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int     main( void )
{
	try
    {
        std::srand(std::time(0));

        for (size_t cur = 0; cur < 3; cur++)
        {
            std::cout << GREEN << "Iteration " << RESET << cur + 1 << ":" << std::endl;

            Base *randBase = generate();

            std::cout << GREEN << "Pointer: " << RESET;
            identify(randBase);

            std::cout << GREEN << "Reference: " << RESET;
            identify(*randBase);

            delete randBase;

            std::cout << YELLOW << "------------------------" << RESET << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "An error occurred: " << RESET << e.what() << std::endl;
        return 1;
    }

    return 0;
}