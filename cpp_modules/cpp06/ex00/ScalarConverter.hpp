#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cfloat>
#include <limits.h>
#include <iomanip>

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

enum ScalarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    UNKNOWN
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();
        ScalarConverter & operator=(ScalarConverter const &other);
        static ScalarType checkType(const std::string& input);

    public:
        static void convert(std::string input);
};