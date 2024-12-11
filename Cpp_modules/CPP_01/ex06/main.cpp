/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:53:24 by alanty            #+#    #+#             */
/*   Updated: 2024/08/07 12:56:05 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl grumblerHarl;
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl
			<< "Levels are: DEBUG -INFO - WARNING - ERROR" << std::endl;
		return 0;
	}
	grumblerHarl.complain(argv[1]);
	return 0;
}
