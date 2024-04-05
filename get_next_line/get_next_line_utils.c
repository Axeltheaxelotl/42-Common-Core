/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:30:47 by alanty            #+#    #+#             */
/*   Updated: 2024/03/14 14:16:31 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdio.h>

size_t	ft_strlen(const char *thestring)
{
	int	i;

	i = 0;
	while (thestring[i])
		i++;
	return (i);
}

char	*strjoint(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *string, int rechercheChar)
{
	char	*str;

	str = (char *)string;
	while (*str != rechercheChar && *str != 0)
		str++;
	if (*str == rechercheChar)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementcompter, size_t elementsize)
{
	char	*res;

	res = malloc(elementcompter * elementsize);
	if (!res)
		return (NULL);
	ft_bzero(res, elementsize * elementcompter);
	return (res);
}
/*
int	main()
{
	char *s1 = "Hello";
	char *s2 = "World";
	char *resultat_strjoint = strjoint(s1, s2);
	printf("Résultat de strjoint : %s\n", resultat_strjoint);
	free(resultat_strjoint);

	const char *string = "Bonjour";
	int rechercheChar = 'o';
	char *resultat_strchr = ft_strchr(string, rechercheChar);
	printf("Résultat de ft_strchr : %s\n", resultat_strchr);

	char test_bzero[10];
	bzero(test_bzero, 10);
	printf("Résultat de bzero : %s\n", test_bzero);

	int *tab = ft_calloc(5, sizeof(int));
	printf("Résultat de ft_calloc : ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
	free(tab);

	const char *thestring = "Test";
	size_t resultat_strlen = ft_strlen(thestring);
	printf("Résultat de ft_strlen : %zu\n", resultat_strlen);

	return 0;
}
*/
