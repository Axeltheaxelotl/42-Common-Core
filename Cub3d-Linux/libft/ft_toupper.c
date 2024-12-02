/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:47:10 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:39:00 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a lower-case letter to the corresponding upper-case letter.
 *
 * @param c The character to convert.
 * @return The corresponding upper-case letter if c is a lower-case letter,
 * c otherwise.
 */

int	ft_toupper(int c)
{
	while (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_toupper(104));
}
*/
