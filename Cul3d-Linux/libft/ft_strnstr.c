/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:52:06 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 20:08:47 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t		ft_strlen(const char *s);

static char	*find_substring(const char *big, const char *little, size_t len,
		size_t little_len)
{
	const char	*big_end;
	size_t		k;

	if (little_len > len)
		return (NULL);
	big_end = big + len - little_len + 1;
	while (*big && big < big_end)
	{
		if (*big == little[0])
		{
			k = 0;
			while (k < little_len && big[k] == little[k])
				k++;
			if (k == little_len)
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len > len)
		return (NULL);
	return (find_substring(big, little, len, little_len));
}
