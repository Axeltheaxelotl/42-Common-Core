/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:22:48 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:38:15 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Appends a character to a string.
 *
 * @param start The string to append to.
 * @param c The character to append.
 * @return The new string with the character appended.
 */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_appendchar(char *start, char c)
{
	size_t	i;
	char	*tmp;

	tmp = malloc(ft_strlen(start) + 2);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		tmp[i] = start[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(start);
	return (tmp);
}
