#include "ScalarConverter.hpp"

static bool checkChar(const std::string& input)
{
    if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0]))
        return true;
    return false;
}

static bool checkInt(const std::string& input)
{
    size_t start = 0;
    if (input.size() == 1 && (input[0] == '+' || input[0] == '-'))
    {
        std::cerr << "Error: Invalid float format!" << std::endl;
        return false;
    }
    start = 1;
    for (size_t i = start; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            std::cerr << "Error: Invalid characters in integer!" << std::endl;
            return false;
        }
    }
    long n = 0;
    bool isNegative = (input[0] == '-');
    for (size_t i = start; i < input.size(); i++)
    {
        n = n * 10 + (input[i] - '0');
        if ((!isNegative && n > INT_MAX) || (isNegative && -n < INT_MIN))
        {
            std::cerr << "Error: Integer out of range!" << std::endl;
            return false;
        }
    }
    return true;
}

static bool checkFloat(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+')
        start = 1;

    bool pointFound = false;
    bool hasDigits = false;

    for (size_t i = start; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            hasDigits = true;
        else if (input[i] == '.' && !pointFound)
            pointFound = true;
        else if (input[i] == 'f' && i == input.size() - 1)
            continue;
        else
        {
            std::cerr << "Error: Invalid characters in float!" << std::endl;
            return false;
        }
    }
    return true;
}

static bool checkDouble(const std::string &input)
{
    bool pointFound = false;
    int digitCount = 0;
    size_t i = 0;

    if (input[0] == '+' || input[0] == '-')
        i++;

    for (; i < input.length(); i++)
    {
        if (isdigit(input[i]))
            digitCount++;
        else if (input[i] == '.' && !pointFound)
            pointFound = true;
        else
            return false;
    }
    return pointFound && digitCount > 0;
}

static bool checkPseudoLiterals(const std::string& input)
{
    if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" ||
        input == "-inff" || input == "+inff") {
        return true;
    }
    else
        std::cerr << "Error: Invalid pseudo-literal!" << std::endl;
    return false;
}

ScalarType ScalarConverter::checkType(const std::string& input)
{
    if (checkChar(input))
        return CHAR;
    if (checkFloat(input))
        return FLOAT;
    if (checkDouble(input))
        return DOUBLE;
    if (checkInt(input))
        return INT;
    if (checkPseudoLiterals(input))
        return PSEUDO_LITERAL;
    return UNKNOWN;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) {*this = src;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other)
{
    (void)other;
    return *this;
}

static void charConvert(std::string param)
{
        char c = param[0];
        std::cout << GREEN << "char: '" <<  RESET << c << "'" << std::endl;
        std::cout << GREEN << "int: " << RESET << static_cast<int>(c) << std::endl;
        std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << GREEN << "double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void intConvert(std::string param)
{
    int n = atoi(param.c_str());

    if (n < 0 || n > 127)
        std::cout << RED << "char: impossible" << RESET << std::endl;
    else if (!isprint(n))
        std::cout << RED << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: '" << RESET << static_cast<char>(n) << "'" << std::endl;

    std::cout << GREEN << "int: " << n << RESET << std::endl;
    std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << GREEN << "double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void floatConvert(std::string param)
{
    float n = atof(param.c_str());

    if (n < 0 || n > 127)
        std::cout << RED << "char: impossible" << RESET << std::endl;
    else if (!isprint(n))
        std::cout << RED << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: '" << RESET << static_cast<char>(n) << "'" << std::endl;

    std::cout << GREEN << "int: " << RESET << static_cast<int>(n) << std::endl;
    std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << n << "f" << std::endl;
    std::cout << GREEN <<"double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void doubleConvert(std::string param)
{
    double n = atof(param.c_str());

    if (n < 0 || n > 127)
        std::cout << RED << "char: impossible" << RESET << std::endl;
    else if (!isprint(n))
        std::cout << RED << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: '" << RESET << static_cast<char>(n) << "'" << std::endl;

    std::cout << GREEN << "int: " << RESET << static_cast<int>(n) << std::endl;
    std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << GREEN << "double: " << RESET << std::fixed << std::setprecision(1) << n << std::endl;
}

static void infConvert(std::string param)
{
    if (param == "nan" || param == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (param == "-inf" || param == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << INT_MIN << std::endl;
        std::cout << "float: " << __FLT_MIN__ << std::endl;
        std::cout << "double: " << __DBL_MIN__ << std::endl;
    }
    else if (param == "+inf" || param == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << INT_MAX << std::endl;
        std::cout << "float: " << __FLT_MAX__ << std::endl;
        std::cout << "double: " << __DBL_MAX__ << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
   ScalarType type = ScalarConverter::checkType(input);
    switch (type)
    {
        case CHAR: charConvert(input); break;
        case FLOAT: floatConvert(input); break;
        case DOUBLE: doubleConvert(input); break;
        case INT: intConvert(input); break;
        case PSEUDO_LITERAL: infConvert(input); break;
        case UNKNOWN: std::cout << "Unknown type" << std::endl; break;
    }
}