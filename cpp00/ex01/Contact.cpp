/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 10:27:29 by naanapa           #+#    #+#             */
/*   Updated: 2025-01-13 10:27:29 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string name)
{
	this->_name = name;
}
void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}
void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
std::string	Contact::getFirstName(void) const
{
	return (_name);
}
std::string	Contact::getLastName(void) const
{
	return (_lastName);
}
std::string	Contact::getNickName(void) const
{
	return (_nickName);
}
std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}
std::string Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}