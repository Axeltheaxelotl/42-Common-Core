/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:42:15 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 18:46:16 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (!SedForLosers::replaceInFile(filename, s1, s2))
	{
		std::cerr << "Èchec de l'operation de remplacement." << std::endl;
		return 1;
	}
	std::cout << "Remplacement termine avec succes." << std::endl;
	return 0;
}
