/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:34:52 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 10:37:32 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	delete heapZombie;

	randomChump("StackZombie");
	return 0;
}
