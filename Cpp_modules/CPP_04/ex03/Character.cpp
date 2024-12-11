/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:26:48 by alanty            #+#    #+#             */
/*   Updated: 2024/09/04 11:47:31 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = nullptr;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; ++i)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i) // Bug ici corrigé (remplacer ":" par ";")
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}
