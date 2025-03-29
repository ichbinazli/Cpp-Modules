/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 10:29:41 by naanapa           #+#    #+#             */
/*   Updated: 2025-01-13 10:29:41 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	int index;

  public:
	void addContact();
	void searchContact() const;
	void printUserInformation(int i) const;
	void printPhoneBook(int i) const;
};

std::string get_input();

#endif