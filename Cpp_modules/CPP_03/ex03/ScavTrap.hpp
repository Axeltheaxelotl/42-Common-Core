/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:00:39 by alanty            #+#    #+#             */
/*   Updated: 2024/08/12 16:56:13 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : virtual public ClapTrap
{
	public:
		//Constructeur avec parametre pour le nom
		ScavTrap(const std::string& name);

		//Constructeur de recopie
		ScavTrap(const ScavTrap& other);

		//Operateur d'assignation
		ScavTrap& operator=(const ScavTrap& other);

		//Destructeur
		~ScavTrap();

		//Methode d'attaque specifique a ScavTrap
		void attack(const std::string& target);

		//Methode special pour activer le mode Cate Keeper
		void guardGate();
};

#endif
