/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:25:33 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 15:27:41 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif
