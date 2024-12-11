/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:04:02 by alanty            #+#    #+#             */
/*   Updated: 2024/09/04 10:48:07 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* use materia on " << target.getName() << " *" << std::endl;
}
