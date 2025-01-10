/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:34:14 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 15:02:42 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	i = 3;
	while (i <= (int)sqrt(n))
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
