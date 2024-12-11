/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:26:52 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 18:29:12 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif
