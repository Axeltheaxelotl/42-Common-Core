/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:25:48 by alanty            #+#    #+#             */
/*   Updated: 2024/09/03 09:51:58 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "constructeur WrongAnimal appele" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "destructeur WrongAnimal appele" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Un mauvais bruit d'animal!" << std::endl;
}
