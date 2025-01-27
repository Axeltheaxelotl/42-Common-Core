/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:24:25 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:51:40 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	count_words(char const *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (words);
}

char	*ft_strdup_c(const char *s, char c)
{
	unsigned int	len;
	char			*dup;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		len++;
	}
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

/**
 * Splits a string into words using the character c as a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of strings, or NULL if the allocation fails.
 */

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			words[i] = ft_strdup_c(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
