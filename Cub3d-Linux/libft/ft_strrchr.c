/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:24:29 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:41:08 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Locates the last occurrence of c (converted to a char) in the string s.
 * The terminating null character is considered to be part of the string.
 *
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the located character,
	or NULL if the character does not appear in the string.
 */

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			save = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (save);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s = "wdeuhehiwd";
	int			c;
	char		*result;

	c = 'd';
	result = ft_strrchr(s, c);
	if (result != NULL)
		printf("found '%c' at position %ld\n", c, result - s);
	else
		printf("'%c' not found", c);
}
*/
