/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:28:09 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 12:28:13 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	char			*str_val;
	unsigned int	i;

	str_val = (char *)str;
	i = 0;
	while (i < len)
	{
		if (str_val[i] == c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
