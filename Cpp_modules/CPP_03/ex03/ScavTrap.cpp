/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:06:31 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 11:10:01 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << this->name << " assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attacks " << target
			<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
	}
}

//Methode speciale pour activer le mode de Cate Keeper
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << "is now in Gate Keeper mode." << std::endl;
}
