/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:19:05 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 18:21:41 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP


#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif
