/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:31:53 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:36:55 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a string is composed only of digits.
 *
 * @param str The string to check.
 * @return 1 if the string is composed only of digits, 0 otherwise.
 */

#include <stddef.h>

int	ft_isdigit(int c);

int	ft_isdigits(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
