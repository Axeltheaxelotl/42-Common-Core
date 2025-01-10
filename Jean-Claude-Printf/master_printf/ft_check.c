/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:58:41 by alanty            #+#    #+#             */
/*   Updated: 2024/11/20 13:58:48 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *format, int pos)
{
	int	p_count;
	int	i;

	i = pos;
	p_count = 0;
	while (format[i] && !ft_strchr("cspdiuoxX%", format[i]))
	{
		if (format[i] == '.')
			p_count += 1;
		i++;
	}
	if (p_count > 1)
		return (1);
	return (0);
}

static void	ft_bonusflags(t_struct *item)
{
	if (item->hash)
		item->length += write(1, "#", 1);
	if (item->plus)
		item->length += write(1, "+", 1);
	if (item->space && !item->plus)
		item->length += write(1, " ", 1);
	if (item->dash)
		item->length += write(1, "-", 1);
	if (item->zero && !item->dash)
		item->length += write(1, "0", 1);
}

int	ft_err(t_struct *item, const char *format, int pos)
{
	int	flag;

	flag = 0;
	item->length += write(1, "%", 1);
	ft_bonusflags(item);
	while (format[pos] && format[pos] != '%')
	{
		item->length += write(1, &format[pos], 1);
		if (!flag && format[pos] == '.')
		{
			if (format[pos + 1] != '0')
			{
				item->length += write(1, "0", 1);
				flag = 1;
			}
		}
		pos++;
	}
	if (format[pos] == '%')
		init_struct(item);
	return (pos - 1);
}
