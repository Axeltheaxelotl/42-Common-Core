/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_nombre_vers_chaine.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:55:27 by alanty            #+#    #+#             */
/*   Updated: 2024/02/28 13:19:32 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	longeur_chaine(const char *str)
{
	size_t	longeur;

	if (!str)
		return (0);
	longeur = 0;
	while (str[longeur])
		longeur++;
	return (longeur);
}

void	remplir_zero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

void	*ft_calloc_pf(size_t nombre, size_t taille)
{
	void	*dest;

	dest = malloc (nombre * taille);
	if (!dest)
		return (NULL);
	remplir_zero(dest, nombre * taille);
	return (dest);
}

static size_t	longeur_nombre(unsigned long long n, char *base)
{
	size_t				longeur;
	unsigned long long	base_longeur ;

	longeur = 1;
	base_longeur = longeur_chaine(base);
	while (n >= base_longeur)
	{
		n /= base_longeur;
		longeur++;
	}
	return (longeur);
}

char	*conversion_nombre_vers_chaine(unsigned long long n, char *base)
{
	char	*str;
	int		longeur_nombre_base;
	int		base_longeur;

	longeur_nombre_base = longeur_nombre(n, base);
	base_longeur = longeur_chaine(base);
	str = ft_calloc_pf((longeur_nombre_base + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (longeur_nombre_base)
	{
		longeur_nombre_base--;
		str[longeur_nombre_base] = base[n % base_longeur];
		n /= base_longeur;
	}
	return (str);
}
