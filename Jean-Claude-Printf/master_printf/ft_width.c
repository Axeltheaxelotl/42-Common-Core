/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:00:57 by smasse            #+#    #+#             */
/*   Updated: 2024/09/11 19:17:38 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_width(t_struct *item, const char *s, int pos)
{
	int	res;

	res = 0;
	while (ft_isdigit(s[pos]) && !ft_strchr(".cspdiuoxX%", s[pos]))
	{
		res = res * 10 + s[pos] - '0';
		pos++;
	}
	item->width = res;
	return (--pos);
}

int	ft_decimal(t_struct *item, const char *s, int pos)
{
	int	res;

	res = 0;
	while (ft_isdigit(s[pos]) && !ft_strchr("cspdiuoxX%", s[pos]))
	{
		res = res * 10 + s[pos] - '0';
		pos++;
	}
	item->precision = res;
	return (--pos);
}
