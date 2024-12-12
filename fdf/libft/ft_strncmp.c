/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:38:47 by alanty            #+#    #+#             */
/*   Updated: 2024/02/20 15:28:59 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	tab1[] = "bonsoir";
	char	tab2[] = "bonjour";

	int	resultat = ft_strncmp(tab1, tab2, 7);

	if(resultat == 0)
	{
		printf("%s est egale a %s %u caracteres\n", tab1, tab2, 7);
	}
	else if (resultat < 0)
	{
		printf("%s est superieur a %s %u caracteres\n", tab1, tab2, 7);
	}
	else
	{
		printf("%s est inferieur a %s %u caracteres\n", tab1, tab2, 7);
	}
	
	return 0;
}
*/
