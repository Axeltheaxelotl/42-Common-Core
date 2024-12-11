/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:23:25 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 15:25:24 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		void attack() const;
};

#endif
