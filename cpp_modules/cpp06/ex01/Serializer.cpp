#include "Serializer.hpp"

Serializer::Serializer() { }

Serializer::Serializer(Serializer const &serializer) {*this = serializer;}

Serializer::~Serializer() { }

Serializer & Serializer::operator=(Serializer const &serializer)
{
	if (this != &serializer)
	{
		(void)serializer;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}