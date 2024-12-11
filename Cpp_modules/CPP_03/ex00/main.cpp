/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:49:25 by alanty            #+#    #+#             */
/*   Updated: 2024/08/26 10:06:34 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clappy("Clappy");
	clappy.attack("un bandit");
	clappy.takeDamage(5);
	clappy.beRepaired(3);
        clappy.takeDamage(10);
	clappy.attack("un autre bandit");
	clappy.beRepaired(2);

	return 0;
}


