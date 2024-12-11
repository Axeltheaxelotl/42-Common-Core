/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:12:19 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 18:16:57 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

//Declaration de la classe Fixed
class Fixed
{
	private:
		int fixed_point_value;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
