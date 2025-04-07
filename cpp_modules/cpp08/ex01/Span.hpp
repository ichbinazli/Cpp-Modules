#ifndef SPAN_HPP
#define SPAN_HPP

#define BLUE "\033[34m"
#define RESET "\033[0m"

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int n);
		Span &operator=(const Span &span);
		~Span();
		void addNumber(int n);
		void addNumber(int n , int m);
		int shortestSpan();
		int longestSpan();
		class NoValueException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
