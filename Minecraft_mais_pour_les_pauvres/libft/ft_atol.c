/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:29:15 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:59:53 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a string into a long integer number. This
 * function will skip any whitespace characters, then
 * process any + or - signs and convert the remaining
 * number until the string ends or at the first occurrence
 * of a non-numeric character.
 *
 * @param s The string to convert.
 * @return The number extracted from the string.
 */

int		ft_isdigit(int c);

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
