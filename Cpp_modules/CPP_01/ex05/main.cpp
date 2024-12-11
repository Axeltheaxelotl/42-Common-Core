/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:09:35 by alanty            #+#    #+#             */
/*   Updated: 2024/08/07 10:14:15 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "Testing INFO level:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "Testing WARNING level:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "Testing ERROR level:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "Testing invalid level:" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	return 0;
}
