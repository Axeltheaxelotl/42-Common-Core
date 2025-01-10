/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:03:49 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:39:00 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dest, char *src);

char	*ft_strcpy2(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * Allocates and returns a new string, which is the result of the concatenation
 * of s1 and s2.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	char	*sjoin;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	sjoin = (char *)malloc(len1 + len2 + 1);
	if (sjoin == NULL)
		return (NULL);
	if (s1)
		ft_strcpy2(sjoin, s1);
	if (s2)
		ft_strcat(sjoin, (char *)s2);
	return (sjoin);
}
/*
#include <stdio.h>

int	main(void)
{
	char const *s1 = "abc";
	char const *s2 = "defg";
	printf("%s\n", ft_strjoin(s1, s2));
}*/
