#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _n(n)  {_v.reserve(n);}

Span &Span::operator=(const Span &span)
{
	if (this != &span)
	{
		_n = span._n;
		_v = span._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v.size() == _n)
		throw NoValueException();
	_v.push_back(n);
}

void Span::addNumber(int n, int m)
{
	for (; n <= m; n++)
		addNumber(n);
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::length_error("Less than 2 values");
	
        std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int shortest = tmp[1] - tmp[0];
	
    for (size_t i = 0; i < tmp.size() - 1; i++)
		if (tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	return shortest;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::length_error("Less than 2 values");
	
        std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

const char *Span::NoValueException::what() const throw()
{
	return "No Value Exception";
}
