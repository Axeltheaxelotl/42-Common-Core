/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:14:04 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 11:10:55 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FargTrap " << this->name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->name << " copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << this->name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destroyed."<< std::endl;
}

//Methode speciale pour demander un High Five
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << "requests a positive high five!" << std::endl;
}
