/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:01:31 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:51:37 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Locates the first occurrence of c (converted to an unsigned char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 *
 * @param s The string to search.
 * @param c The character to search for.
 */

char	*ft_strchr(const char *s, int ch)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	s[] = "deuhehiw";
	int			c;
	char		*result;

	c = 'u';
	result = ft_strchr(s, c);
	if (result != NULL)
		printf("found '%c' at position %ld\n", c, result - s);
	else
		printf("'%c' not found", c);
}
*/
