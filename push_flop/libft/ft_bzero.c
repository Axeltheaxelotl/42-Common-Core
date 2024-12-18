/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:25:58 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 12:26:01 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)s;
	while (i < len)
	{
		str2[i] = 0;
		i++;
	}
	return (str2 = s);
}
