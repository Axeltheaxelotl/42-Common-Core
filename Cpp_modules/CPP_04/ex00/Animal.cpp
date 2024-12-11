/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:13:12 by alanty            #+#    #+#             */
/*   Updated: 2024/09/03 09:49:08 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown Animal")
{
	std::cout << "constructeur Animal appele" << std::endl;
}

Animal::~Animal()
{
	std::cout << "destructeur Animal appele" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Un son d'animal generique!" << std::endl;
}
