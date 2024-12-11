/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:14:04 by alanty            #+#    #+#             */
/*   Updated: 2024/08/27 19:11:55 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FargTrap " << this->name << " est cree." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->name << " est copié." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << this->name << " attribut." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " est detruit."<< std::endl;
}

//Methode speciale pour demander un High Five
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl;
}
