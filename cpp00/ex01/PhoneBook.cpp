/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 10:29:29 by naanapa           #+#    #+#             */
/*   Updated: 2025-01-13 10:29:29 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>

std::string get_input(void)
{
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << RED_COLOR << "EOF" << RESET << std::endl;
		exit(0);
	}
	return (input);
}
static bool checkName(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "First Name is empty" << RESET << std::endl;
		return (true);
	}
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (isdigit(input[i]))
		{
			std::cout << BLUE_COLOR << "Name must be only letters" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}

static bool checkNickName(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "Nick Name is empty" << RESET << std::endl;
		return (true);
	}
	return (false);
}
static bool checkDarkestSecret(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "Darkest Secret is empty" << RESET << std::endl;
		return (true);
	}
	return (false);
}
static bool checkPhoneNumber(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR << "Phone Number is empty" << RESET << std::endl;
		return (true);
	}
	if (input.length() != 10)
	{
		std::cout << BLUE_COLOR << "Phone number must be 10 digits" << RESET << std::endl;
		return (true);
	}
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (isalpha(input[i]))
		{
			std::cout << BLUE_COLOR << "Phone number must be only numbers" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}

static bool checkSearchIndex(std::string input)
{
	if (input.empty())
	{
		std::cout << GREEN_COLOR "Index is empty" << RESET << std::endl;
		return (true);
	}
	for (int i = 0; input[i]; i++)
	{
		if (isalpha(input[i]))
		{
			std::cout << RED_COLOR << "False Index !" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}
void PhoneBook::addContact(void)
{
	static int i = 0;

	std::string input;
	index = i;
	do
	{
		std::cout << "First Name: " << std::endl;
		input = get_input();
	} while (checkName(input));
	contacts[i % 8].setFirstName(input);
	do
	{
		std::cout << "Last Name: " << std::endl;
		input = get_input();
	} while (checkName(input));
	contacts[i % 8].setLastName(input);
	do
	{
		std::cout << "Nick Name: " << std::endl;
		input = get_input();
	} while (checkNickName(input));
	contacts[i % 8].setNickName(input);
	do
	{
		std::cout << "Phone Number: " << std::endl;
		input = get_input();
	} while (checkPhoneNumber(input));
	contacts[i % 8].setPhoneNumber(input);
	do
	{
		std::cout << "Darkest Secret: " << std::endl;
		input = get_input();
	} while (checkDarkestSecret(input));
	contacts[i % 8].setDarkestSecret(input);
	std::cout << DARK_BLUE << "Contact added successfully" << RESET << std::endl;
	i++;
	index = i;
}

void PhoneBook::printUserInformation(int i) const
{
	i -= 1;
	if ((i >= index || i < 0) || i >= 8)
	{
		std::cout << RED_COLOR << "Invalid index" << RESET << std::endl;
		;
		return;
	}
	std::cout << "Name: " << contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
	std::cout << "Nick Name: " << contacts[i].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
}

void PhoneBook::printPhoneBook(int i) const
{
    if (i == 0)
    {
        std::cout << "  INDEX" << "       NAME" << "     LASTNAME" << "   NICKNAME"
                  << std::endl;
        std::cout << "----------*----------*----------*----------*" << std::endl;
    }
    
    std::cout << std::setw(10) << i + 1 << "|";
    
    std::string firstName = contacts[i].getFirstName();
    if (firstName.length() > 10)
    {
        firstName = firstName.substr(0, 9) + ".";
    }
    std::cout << std::setw(10) << firstName << "|";
    
    std::string lastName = contacts[i].getLastName();
    if (lastName.length() > 10)
    {
        lastName = lastName.substr(0, 9) + ".";
    }
    std::cout << std::setw(10) << lastName << "|";
    
    std::string nickName = contacts[i].getNickName();
    if (nickName.length() > 10)
    {
        nickName = nickName.substr(0, 9) + ".";
    }
    std::cout << std::setw(10) << nickName << "|" << std::endl;
    
    std::cout << "----------*----------*----------*----------*" << std::endl;
}

void PhoneBook::searchContact() const
{
	int i;

	std::string input;
	i = 0;
	while (i < index && i < 8)
	{
		printPhoneBook(i);
		i++;
	}
	do
	{
		std::cout << "Enter the index of the contact: " << std::endl;
		input = get_input();
	} while (checkSearchIndex(input));
	if (input.length() == 1 && isdigit(input[0]))
		printUserInformation(std::atoi(input.c_str()));
	else
		std::cout << RED_COLOR << "Invalid index" << RESET << std::endl;
}