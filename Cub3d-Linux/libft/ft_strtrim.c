/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:11:02 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:39:58 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

int	check_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/**
 * Allocates (with malloc(3)) and returns a copy of 's1' with the characters
 * specified in 'set' removed from the beginning and the end of the string.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && check_set(s1[i + start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && check_set(s1[end - 1], set))
		end--;
	trimmed = malloc((end - start + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	while ((start + i) < end)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
