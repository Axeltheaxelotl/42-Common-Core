/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:35:19 by alanty            #+#    #+#             */
/*   Updated: 2024/08/12 16:59:28 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << this->name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap " << this->name << " assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " and my ClapTrap is " << ClapTrap::name << "." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
