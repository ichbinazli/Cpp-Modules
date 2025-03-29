/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 14:07:51 by naanapa           #+#    #+#             */
/*   Updated: 2025-01-15 14:07:51 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime> 

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0; 
int	Account::_totalNbDeposits = 0; 
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";created" << std::flush << std::endl;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";closed" << std::flush << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts++);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits++);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals++);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << GREEN << "accounts:" << _nbAccounts << ";" << std::flush;
	std::cout << "total:" << _totalAmount << ";" << std::flush;
	std::cout << "deposits:" << _totalNbDeposits << ";" << std::flush;
	std::cout << "withdrawals:" << _totalNbWithdrawals << END << std::flush << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);

    std::cout << std::setfill('0') << "["
              << std::setw(4) << 1900 + localTime->tm_year
              << std::setw(2) << 1 + localTime->tm_mon
              << std::setw(2) << localTime->tm_mday << "_"
              << std::setw(2) << localTime->tm_hour
              << std::setw(2) << localTime->tm_min
              << std::setw(2) << localTime->tm_sec
              << "] " << std::flush;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	getNbDeposits();
	std::cout << YELLOW << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "p_amount:" << _amount << ";" << std::flush;
	std::cout << "deposit:" << deposit << ";" << std::flush;
	std::cout << "amount:" << _amount + deposit << ";" << std::flush;
	std::cout << "nb_deposit:" << ++_nbDeposits << END << std::flush << std::endl;
	_totalAmount += deposit;
	_amount += deposit;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << BLUE << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "p_amount:" << _amount << ";" << std::flush;
	if (withdrawal <= _amount && withdrawal > 0)
	{
		getNbWithdrawals();
		std::cout << "withdrawal:" << withdrawal << ";" << std::flush;
		std::cout << "amount:" << _amount - withdrawal << ";" << std::flush;
		std::cout << "nb_withdrawals:" << ++_nbWithdrawals << END << std::flush << std::endl;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		return (true);
	}
	std::cout << RED << "refused" << END << std::flush << std::endl;
	return (false);
}

int		Account::checkAmount(void) const
{
	std::cout << "checkAmount" << std::flush << std::endl;
	return (0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << CYAN << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "deposits:" << _nbDeposits << ";" << std::flush;
	std::cout << "withdrawals:" << _nbWithdrawals << END << std::flush << std::endl;
}