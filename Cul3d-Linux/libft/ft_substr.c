/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:22:47 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:39:48 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(char const *src);

/**
 * Allocates and returns a substring from the string s. The substring begins at
 * index start and is of maximum size len.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in s.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;
	size_t	length;

	i = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (start >= length)
		return (ft_strdup(""));
	if (start + len > length)
		len = length - start;
	s2 = malloc((len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
