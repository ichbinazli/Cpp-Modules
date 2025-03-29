/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 10:28:49 by naanapa           #+#    #+#             */
/*   Updated: 2025-01-13 10:28:49 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string input;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			input = av[i];
			for (size_t i = 0; i < input.length(); i++)
				std::cout << (char)std::toupper(input[i]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}