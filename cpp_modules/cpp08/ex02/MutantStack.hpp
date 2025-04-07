
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::deque;
using std::vector;
using std::stack;



template <typename T, typename C = std::deque<T> >

class MutantStack : public stack<T, C>
{
	public:
		MutantStack() : stack<T>() {}
		MutantStack(const MutantStack<T>& other) : stack<T, C>(other) {}
		MutantStack<T>& operator=(const MutantStack<T>& other) {
			if (this != &other) {
				stack<T, C>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}

		typedef typename stack<T, C>::container_type::iterator iterator;

		iterator begin() { return stack<T, C>::c.begin(); }
		iterator end() { return stack<T, C>::c.end(); }
};

#endif
