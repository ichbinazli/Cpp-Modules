#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

#include <iostream>
#include <exception>
#include <algorithm>


template <typename T>

typename T::iterator easyfind(T &container, int value) 
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif