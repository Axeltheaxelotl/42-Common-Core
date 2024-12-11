/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:17:12 by alanty            #+#    #+#             */
/*   Updated: 2024/09/03 09:50:51 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "construteur Dog appele" << std::endl;
}

Dog::~Dog()
{
	std::cout << "destructeur Dog appeldestructeur Dog appele" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
