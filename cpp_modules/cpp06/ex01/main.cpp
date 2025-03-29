#include "Serializer.hpp"
#include <cstdio>

int main()
{
    try {
        Data *ptr = new Data;

        std::cout << GREEN << "Default address: " << RESET << ptr << std::endl;
        std::cout << std::endl;

        uintptr_t a = Serializer::serialize(ptr);
        std::cout << GREEN << "Serialized value: " << RESET << a << std::endl;
        std::cout  << std::endl;

        ptr = Serializer::deserialize(a);
        std::cout << GREEN << "Deserialized address: " << RESET << ptr << std::endl;
        std::cout << std::endl;

        delete ptr;
    } catch (std::exception &e) {
        std::cerr << "Error:  " << e.what() << std::endl;
    }

    return 0;
}