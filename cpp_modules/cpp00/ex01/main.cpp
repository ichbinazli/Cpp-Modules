/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 11:10:08 by naanapa           #+#    #+#             */
/*   Updated: 2025-01-13 11:10:08 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	(void) av;

	if(ac == 1)

	{
		PhoneBook	input;
 		std::string str;
		while (1)
		{
			str = get_input();
			if (str == "EXIT")
				break ;
			else if (str == "ADD")
				input.addContact();
			else if (str == "SEARCH")
				input.searchContact();
			else
				std::cout  << RED_COLOR << "Invalid command" << RESET << std::endl;
		}
	}
	else 
		std::cout  << RED_COLOR << " BAD ARGUMENT ! " << RESET << std::endl;


	return (0);
}