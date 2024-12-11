/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:52:43 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 18:58:12 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int arraySize = 10;
	Animal* animals[arraySize];

	//Remplir la moitie avec des Dog et l'autre moitie avec des Cat
	for (int i = 0; i < arraySize / 2; ++i)
	{
		animals[i] = new Dog();
	}

	for (int i = arraySize / 2; i < arraySize; ++i)
	{
		animals[i] = new Cat();
	}

	//Suppression des animaux
	for (int i = 0; i < arraySize; ++i)
	{
		delete animals[i];
	}

	return 0;
}
