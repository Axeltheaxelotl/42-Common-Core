/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:51:44 by alanty            #+#    #+#             */
/*   Updated: 2024/08/21 14:36:55 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point p(5, 10); //Point a tester
	
	if (bsp(a, b, c, p))
	{
		std::cout << "Le point est a l'interieur du triangle." << std::endl;
	}
	else
	{
		std::cout << "Le point n'est pas a l'interieur du triangle" << std::endl;
	}
	return 0;
}
