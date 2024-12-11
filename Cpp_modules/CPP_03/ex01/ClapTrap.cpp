/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:11:03 by alanty            #+#    #+#             */
/*   Updated: 2024/08/27 19:01:56 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " est cree !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " est detruit." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attaque " << target
			<< ", causant" << this->attackDamage << " points de degats !" << std::endl;
		energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " n'a pas assez de points de vie ou d'energie pour attaquer." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		hitPoints -= amount;
		if (hitPoints < 0) hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " subit " << amount << " points de degats !" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " est deja detruit." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << this->name << " se repare de " << amount << " points de vie !" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " n'a pas assez de points de vie pour se reprer." << std::endl;
	}
}
