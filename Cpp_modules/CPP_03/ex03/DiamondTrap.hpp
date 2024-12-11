/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:29:39 by alanty            #+#    #+#             */
/*   Updated: 2024/08/12 16:35:15 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name; //Nom specifique a DiamondTrap
	
	public:
		//Construteur avec parametre pour le nom
		DiamondTrap(const std::string& name);
		
		//Constructeur de recopie
		DiamondTrap(const DiamondTrap& other);

		//Operateur d'assignation
		DiamondTrap& operator=(const DiamondTrap& other);

		~DiamondTrap();

		//Methode speciale pour afficher les noms
		void whoAmI();

		//Redefinition de la methode attack (heritee de ScavTrap)
		void attack(const std::string& target);
};

#endif
