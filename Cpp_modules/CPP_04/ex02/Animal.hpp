/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:50:14 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 18:52:35 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		std::string getType() const;

		//Methode purement virtuelle, rendant la classe Animal abstraite
		virtual void makeSound() const = 0;
};

#endif
