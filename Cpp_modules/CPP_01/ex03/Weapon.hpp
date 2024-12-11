/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:19:43 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 15:21:32 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string type);
		const std::string& getType() const;
		void setType(std::string type);
};

#endif
