/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:51:28 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 10:55:09 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int N = 5; //Nombre de Zombies dans la horde
	Zombie* horde = zombieHorde(N, "HordeZombie");

	for(int i = 0; i < N; ++i)
	{
		horde[i].announce();
	}
	delete[] horde; //Liberer la memoire allouee pour la horde
	return 0;
}
