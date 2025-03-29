#ifndef ITER_HPP

# define ITER_HPP

#include <iostream>

# define RESET "\x1b[0m"
#define PINK "\x1b[35;01m"
#define YELLOW "\x1b[33;01m"


template <typename T , typename F>
void iter(T *arr, size_t len, F f)
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void print(T arr)
{
    std::cout << YELLOW << arr << RESET << std::endl;
}

#endif