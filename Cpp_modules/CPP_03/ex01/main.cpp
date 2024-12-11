/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:17:31 by alanty            #+#    #+#             */
/*   Updated: 2024/08/12 18:34:00 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	//Creation d'un ScavTrap nommé "Scavvy"
	ScavTrap scavvy("Scavvy");

	//Utilisation de le methode attack heritee de ClapTrap
	scavvy.attack("un brigant");

	//Utilisation de la methode guardGate specifique a ScavTrap
	scavvy.guardGate();

	//Utikisation des methodes takeDamage et beRepaired heritees de ClapTrap
	scavvy.takeDamage(30);
	scavvy.beRepaired(20);

	return 0;
}
