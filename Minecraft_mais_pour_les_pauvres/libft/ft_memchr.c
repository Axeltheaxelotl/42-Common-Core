/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:34:04 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 15:03:13 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Locates the first occurrence of c (converted to an unsigned char) in string s.
 *
 * @param s The string to search in.
 * @param c The character to search for.
 * @param n The number of bytes to search.
 * @return A pointer to the located character,
	or NULL if the character does not appear in the string.
 */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		chr;
	const unsigned char	*str;

	str = s;
	chr = c;
	while (n > 0)
	{
		if (*str == chr)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
/*
#include <stddef.h>
#include <stdio.h>
#include <string.h>

//#include "your_header_file.h"

int	main(void)
{
	char	s[] = {0, 1, 2 ,3 ,4 ,5};
	int		c;
	size_t	n;
	void	*result;

	c = 0;
	n = 1;
	result = ft_memchr(s, c, n);
	if (result != NULL) {
		printf("found '%d' in '%s'at %p\n", c, s, result);
	} else {
		printf("'%c' not found in %zu characters of '%s'\n", c, n, s);
	}
	return (0);
}
*/
