#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << BLUE << "Shortest span: " << RESET << sp.shortestSpan() << std::endl;
		std::cout << BLUE << "Longest span: " << RESET << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
