/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:22:31 by alanty            #+#    #+#             */
/*   Updated: 2024/03/01 17:52:30 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	formatteur(va_list va, char *str, size_t *compteur)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), compteur);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), compteur);
	else if (*str == 'p')
		affiche_pointeur(va_arg(va, void *), compteur);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), compteur);
	else if (*str == 'u')
		affiche_nombre_non_signe(va_arg(va, unsigned int), compteur);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			aff_hexadecimal(va_arg(va, unsigned int), compteur, HEX_LOW_BASE);
		else
			aff_hexadecimal(va_arg(va, unsigned int), compteur, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar_pf(*str, compteur);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	compteur;

	if (!str)
		return (0);
	compteur = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			formatteur(args, (char *)str, &compteur);
		}
		else
			ft_putchar_pf(*str, &compteur);
		str++;
	}
	va_end(args);
	return (compteur);
}
