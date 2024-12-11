/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:06:31 by alanty            #+#    #+#             */
/*   Updated: 2024/08/27 19:03:30 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " est cree." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " copier." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << this->name << " attribue." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " est detruit." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attaque " << target
			<< ", causent " << this->attackDamage << " points de dommages!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " ne peut pas attaquer." << std::endl;
	}
}

//Methode speciale pour activer le mode de Cate Keeper
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << "is now in Gate Keeper mode." << std::endl;
}
