/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:09:13 by alanty            #+#    #+#             */
/*   Updated: 2024/08/12 16:13:58 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);

		~FragTrap();

		//Methode speciale pour demander un High Five
		void highFivesGuys(void);
};

#endif
