/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:47:53 by alanty            #+#    #+#             */
/*   Updated: 2024/09/04 12:06:41 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (materias[i])
				delete materias[i];
			materias[i] = other.materias[i] ? other.materias[i]->clone() : nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i])
			delete materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!materias[i])
		{
			materias[i] = m->clone(); // Clone the materia and store it
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return nullptr; // Return nullptr if the type is not found
}
