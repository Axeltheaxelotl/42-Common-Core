/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:32:10 by alanty            #+#    #+#             */
/*   Updated: 2024/09/03 09:53:10 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "constructeur WrongCat appele" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "destructeur WrongCat appele" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Un mauvais bruit d'animal!" << std::endl;
}
