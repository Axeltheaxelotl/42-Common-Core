/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:43:17 by alanty            #+#    #+#             */
/*   Updated: 2024/08/08 19:08:18 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

//Fonction auxilliaire pour calculer la surface d un triangle
Fixed area(Point const a, Point const b, Point const c)
{
	return Fixed(
			static_cast<float>(
				std::abs(
					(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
					 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
					 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0
					)
				)
			);
}

//Fonction bsp pour verifier si un point est dans le triangle
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_abc = area(a, b, c);
	Fixed area_pab = area(point, a, b);
	Fixed area_pbc = area(point, b, c);
	Fixed area_pca = area(point, c, a);

	return (area_abc == (area_pab + area_pbc + area_pca));
}
