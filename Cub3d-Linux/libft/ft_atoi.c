/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:37:34 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 21:37:44 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a string into an integer number. This
 * function will skip any whitespace characters, then
 * process any + or - signs and convert the remaining
 * number until the string ends or at the first occurrence
 * of a non-numeric character.
 *
 * @param str The string to convert.
 * @return The number extracted from the string.
 */

int	ft_isdigit(int c);

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		nb *= 10;
		nb += *nptr - '0';
		nptr++;
	}
	return (nb * sign);
}
