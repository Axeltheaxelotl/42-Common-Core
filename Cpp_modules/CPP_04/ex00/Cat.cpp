/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:20:28 by alanty            #+#    #+#             */
/*   Updated: 2024/09/03 09:49:37 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "constructeur cat appele" << std::endl;
}

Cat::~Cat()
{
	std::cout << "destructeur cat appele" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
