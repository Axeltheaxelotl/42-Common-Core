/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:11:01 by alanty            #+#    #+#             */
/*   Updated: 2024/08/13 18:13:35 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		virtual ~Brain();

		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif
