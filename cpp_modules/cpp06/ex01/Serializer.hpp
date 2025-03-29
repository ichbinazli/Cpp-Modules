#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"

struct Data
{
	std::string id;
	std::string name;
	std::string surname;
	std::string username;
	std::string website;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &serializer);
		~Serializer();
		Serializer & operator=(Serializer const &serializer);
	public:
		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif