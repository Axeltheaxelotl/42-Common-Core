/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:03:19 by alanty            #+#    #+#             */
/*   Updated: 2024/08/06 11:14:57 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	//Variable de type chaine de caracteres initialisee
	std::string str = "HI THIS IS BRAIN";

	//Pointeur vers la chaine de caracteres
	std::string* stringPTR = &str;

	//Reference a la chaine de caracteres
	std::string& stringREF = str;

	//Imprimer les adresse memoire
	std::cout << "Adresse memoire de la variable str       :" << &str << std::endl;
	std::cout << "Adresse memoire contenue dans stringPTR  :" << stringPTR << std::endl;
	std::cout << "Adresse memoire contenue dans stringREF  :" << &stringREF << std::endl;


	//Imprimer les valeurs
	std::cout << "Valeur de la variable str                :" << str << std::endl;
	std::cout << "Valeur pointee par stringPTR             :" << *stringPTR << std::endl;
	std::cout << "Valeur pointee par stringREF             :" << stringREF << std::endl;
	
	return 0;
}
