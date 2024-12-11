/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:30:39 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 18:33:00 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDFORLOSERS_H
# define SEDFORLOSERS_H

#include <iostream>
#include <fstream>
#include <string>

class SedForLosers
{
	public:
		static bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);
};

#endif
