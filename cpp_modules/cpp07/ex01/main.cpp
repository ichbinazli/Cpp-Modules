#include "iter.hpp"

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArr[] = {"one", "two", "three", "four", "five"};

	std::cout << PINK << "Int array:" << RESET << std::endl;
	iter(intArr, 5, print<int>);
	std::cout << PINK << "Float array:" << RESET << std::endl;
	iter(floatArr, 5, print<float>);
	std::cout << PINK << "String array:" << RESET << std::endl;
	iter(stringArr, 5, print<std::string>);
	return 0;
}
