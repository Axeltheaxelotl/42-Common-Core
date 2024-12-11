/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:04 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 18:28:20 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = int_value << fractional_bits;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(float_value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destrutor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		fixed_point_value = other.fixed_point_value;
	}
	return *this;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
	return fixed_point_value >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
