/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:13:00 by alanty            #+#    #+#             */
/*   Updated: 2024/09/04 11:47:47 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria // Correction du nom
{
	public:
		Cure();
		virtual ~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
