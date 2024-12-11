/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:20:38 by alanty            #+#    #+#             */
/*   Updated: 2024/08/27 19:13:01 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	//Creation d'un FragTrap nommé Fraggy
	FragTrap fraggy("Fraggy");

	//Utilisation de la methode attack heritee de ClapTrap
	fraggy.attack("Cible");

	//Utilisation de la methode highFivesGuys specifique a FragTrap
	fraggy.highFivesGuys();

	//Utilisation des methodes takeDamage et beRepaired heritees de ClapTrap
	fraggy.takeDamage(30);
	fraggy.beRepaired(20);

	return 0;
}
