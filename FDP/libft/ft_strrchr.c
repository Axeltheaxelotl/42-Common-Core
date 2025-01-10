/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:43:42 by alanty            #+#    #+#             */
/*   Updated: 2024/02/20 12:46:28 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
	const char *str = "bonjour";
	int c = 'o';
	char *resultat = ft_strrchr(str, c);

	if (resultat != NULL)
	{
		printf("%c, %s\n", c, resultat);
	}
	else
	{
		printf("%c", c);
	}
	return (0);
}
*/
