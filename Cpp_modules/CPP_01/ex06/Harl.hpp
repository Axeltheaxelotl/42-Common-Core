/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:51:02 by alanty            #+#    #+#             */
/*   Updated: 2024/08/07 12:53:18 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

#endif
