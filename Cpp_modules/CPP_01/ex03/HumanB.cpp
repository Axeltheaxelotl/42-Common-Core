/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:27:50 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 15:31:35 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	if (weapon)
	{
		std::cout << name << " attaque avec son " << weapon->getType() << std::endl;

	}
	else
	{
		std::cout << name << " n'a pas d'arme pout attaquer " << std::endl;
	}
}
