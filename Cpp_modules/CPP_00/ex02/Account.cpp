/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:55:49 by alanty            #+#    #+#             */
/*   Updated: 2024/08/07 14:56:24 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	std::stringstream ss;
	ss << (now->tm_year + 1900)
	   << (now->tm_mon + 1 < 10 ? "0" : "") << (now->tm_mon + 1)
	   << (now->tm_mday < 10 ? "0" : "") << now->tm_mday
	   << "_"
	   << (now->tm_hour < 10 ? "0" : "") << now->tm_hour
	   << (now->tm_min < 10 ? "0" : "") << now->tm_min
	   << (now->tm_sec < 10 ? "0" : "") << now->tm_sec;

	std::cout << "[" << ss.str() << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}
