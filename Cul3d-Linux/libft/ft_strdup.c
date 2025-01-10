/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:40:29 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:38:50 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			ft_strlen(const char *s);

static size_t	str_len(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

/**
 * Allocates sufficient memory for a copy of the string s1, does the copy, and
 * returns a pointer to it.
 *
 * @param src The string to copy.
 * @return The pointer to the copy of the string.
 */

char	*ft_strdup(char const *src)
{
	char	*dest;
	char	*start;

	dest = str_new(str_len(src));
	if (!dest)
		return (NULL);
	start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}
