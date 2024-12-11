/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:48:20 by alanty            #+#    #+#             */
/*   Updated: 2024/08/07 18:50:43 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
