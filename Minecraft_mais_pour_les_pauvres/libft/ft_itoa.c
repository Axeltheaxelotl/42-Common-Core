/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:24:33 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:53:21 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nb_length(int n)
{
	int			len;
	long int	nb;

	len = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*itoa_helper(char *num, long n, int len)
{
	int	index;

	index = len - 1;
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	if (n == -2147483648)
	{
		num[0] = ('-');
		num[1] = ('2');
		n = 147483648;
	}
	while (n != 0)
	{
		num[index] = n % 10 + '0';
		n = n / 10;
		index--;
	}
	num[len] = '\0';
	return (num);
}

/**
 * Converts an integer to a string.
 *
 * @param n The integer to convert.
 * @return The string representation of the integer.
 */

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = nb_length(n);
	num = malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (NULL);
	if (n == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	num = itoa_helper(num, (long)n, len);
	return (num);
}
