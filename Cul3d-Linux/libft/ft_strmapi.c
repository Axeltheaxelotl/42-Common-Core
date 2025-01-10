/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:01 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:39:38 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

/**
 * Applies the function f to each character of the string passed as argument
 * by giving its index as first argument to create a new string resulting from
 * the successive applications of f.
 *
 * @param s The string to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of f.
 */

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
