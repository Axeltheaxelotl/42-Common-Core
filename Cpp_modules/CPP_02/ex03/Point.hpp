/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:34:12 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 18:37:08 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;
};

#endif
