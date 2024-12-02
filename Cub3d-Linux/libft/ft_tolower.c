/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:54:58 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:39:03 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts an uppercase letter to the corresponding lowercase letter.
 * If the character is not uppercase, it returns the character unchanged.
 *
 * @param c The character to convert.
 * @return The converted lowercase character,
	or the original character if no conversion is needed.
 */

int	ft_tolower(int c)
{
	while (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_tolower(40));
}
*/
