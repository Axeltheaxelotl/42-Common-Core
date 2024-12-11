/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:26:44 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 18:04:00 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//Constructeurs et Destructeur
Fixed::Fixed() : fixed_point_value(0) {}

Fixed::Fixed(const int int_value)
{
	fixed_point_value = int_value << fractional_bits;
}

Fixed::Fixed(const float float_value)
{
	fixed_point_value = roundf(float_value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed() {}

//Operateur d'assignation
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		fixed_point_value = other.fixed_point_value;
	}
	return *this;
}

//Surchage des operateurs de comparaison
bool Fixed::operator>(const Fixed &other) const
{
	return fixed_point_value > other.fixed_point_value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return fixed_point_value < other.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return fixed_point_value >= other.fixed_point_value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return fixed_point_value <= other.fixed_point_value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return fixed_point_value == other.fixed_point_value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return fixed_point_value != other.fixed_point_value;
}


//Surchage des operateurs arithmetiques
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}



//Surchage des operateurs d'incrementation et de decrementation
Fixed &Fixed::operator++()
{
	++fixed_point_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	--fixed_point_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}


//Fonctions membres statiques
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}


//Conversion de Fixed en int
int Fixed::toInt() const
{
	return fixed_point_value >> fractional_bits;
}

//Conversion de Fixed en float
float Fixed::toFloat() const
{
	return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

//Surchage de l'operateur << pour l'affichage
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
