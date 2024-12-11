/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:33:04 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 18:42:09 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

bool SedForLosers::replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Les chaines de caracteres de rempplacement ne doivent pas être vides." << std::endl;
		return false;
	}
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Erreur lors de l'ouverture du fichier en lecture." << std::endl;
		return false;
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename);
	if (!outputFile)
	{
		std::cerr << "Erreur lors de la creation du fichier de sortie." << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}
