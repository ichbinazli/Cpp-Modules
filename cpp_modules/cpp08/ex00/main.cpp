#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() 
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try {
		std::cout << GREEN << *easyfind(v, 5) << RESET << std::endl;
		std::vector<int>::iterator it = easyfind(v, 3);
		*it = 10;
		std::cout << GREEN << *easyfind(v, 10) << RESET << std::endl;
		std::cout << *easyfind(v, 3) << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << RESET << std::endl;
	}

	std::list<int> l;

	for (int i = 0; i < 10; i++)
		l.push_back(i);
	try {
		std::cout << GREEN << *easyfind(l, 3) << RESET <<  std::endl;
		std::cout << *easyfind(l, 99) << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << RESET << std::endl;
	}
	return 0;
}
