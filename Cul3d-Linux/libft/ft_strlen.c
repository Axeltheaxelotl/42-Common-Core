/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:12:06 by smasse            #+#    #+#             */
/*   Updated: 2024/11/19 17:09:20 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

unsigned int	ft_strlen_fast(const char *s, unsigned int len)
{
	unsigned int	x;

	while (1)
	{
		x = *(unsigned int *)s;
		if (((x - 0x01010101) & ~x & 0x80808080) != 0)
			break ;
		s += 4;
		len += 4;
	}
	while (1)
	{
		x = *(unsigned int *)s;
		if ((x & 0xFF) == 0)
			return (len);
		if ((x & 0xFF00) == 0)
			return (len + 1);
		if ((x & 0xFF0000) == 0)
			return (len + 2);
		if ((x & 0xFF000000) == 0)
			return (len + 3);
		s += 4;
		len += 4;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (((uintptr_t)s & 3) != 0)
	{
		if (*s == '\0')
			return (len);
		s++;
		len++;
	}
	return (ft_strlen_fast(s, len));
}
