/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:44:54 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 11:11:39 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	//Creation d'un DiamondTrap nommé Diamond
	DiamondTrap diamond("Diamond");

	//Utilisation de la methode attack heritee de ScavTrap
	diamond.attack("Target");

	//Utilisation de la methode whoAmI specifique a DiamondTrap
	diamond.whoAmI();

	//Utilisation des methodes takeDamage et beRepired heritees de ClapTrap
	diamond.takeDamage(20);
	diamond.beRepaired(50);

	return 0;
}
