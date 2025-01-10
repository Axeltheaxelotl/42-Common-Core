/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:58:55 by alanty            #+#    #+#             */
/*   Updated: 2024/11/20 13:58:58 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_char(t_struct *item)
{
	char	c;

	c = va_arg(item->args, int);
	if (item->width && !(item->dash))
		ft_align(item, 1);
	item->length += write(1, &c, 1);
	if (item->width && item->dash)
		ft_left_align(item, 1);
	init_struct(item);
}

void	print_str(t_struct *item)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	str = va_arg(item->args, char *);
	if ((!str && item->precision >= 6) || (!str && !item->point))
		str = "(null)";
	if (!str && item->point && item->precision < 6)
		str = "";
	len = ft_strlen(str);
	item->baselen = len;
	if (item->point)
		item->baselen = item->precision;
	if (item->point && item->precision < len)
		len = item->precision;
	if (item->width && !item->dash)
		ft_align(item, len);
	while (str[++i] && i < len)
		item->length += write(1, &str[i], 1);
	if (item->width && item->dash)
		ft_left_align(item, len);
	init_struct(item);
}

void	print_per(t_struct *item)
{
	item->length += write(1, "%", 1);
	init_struct(item);
}
