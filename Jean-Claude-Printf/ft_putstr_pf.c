/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:38:22 by alanty            #+#    #+#             */
/*   Updated: 2024/02/28 12:33:45 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *str, size_t *compteur)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str, compteur);
		str++;
	}
}
