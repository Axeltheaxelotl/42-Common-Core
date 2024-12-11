/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:37:16 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 18:42:01 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Point::~Point() {}

const Fixed &Point::getX() const
{
	return x;
}

const Fixed &Point::getY() const
{
	return y;
}
