/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:15:42 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 17:55:59 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++(); //Pre-incrementation
		Fixed operator++(int); //Post-incrementation
		Fixed &operator--(); //Pre-decrementation
		Fixed operator--(int); //Post-decrementation

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int toInt() const;
		float toFloat() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
