/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:07:42 by alanty            #+#    #+#             */
/*   Updated: 2024/02/20 12:48:27 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char )c)
			return (((unsigned char *)s) + index);
		index++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	char src[] = "bonjour";
	char character = 'r';
	size_t len = sizeof(src) -1;
	char *resultat = ft_memchr(src, character, len);

	if (resultat != NULL)
		{
			printf("%c, %ld.\n", character, (resultat -src));
		}
	else
	{
	printf("%c", character);
	}
	return (0);
}
*/
