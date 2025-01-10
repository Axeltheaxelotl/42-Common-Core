/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:00:39 by smasse            #+#    #+#             */
/*   Updated: 2024/11/06 21:04:26 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_struct *b)
{
	b->dash = 0;
	b->zero = 0;
	b->point = 0;
	b->plus = 0;
	b->space = 0;
	b->hash = 0;
	b->width = 0;
	b->precision = 0;
	b->baselen = 0;
	b->specifier = 0;
	b->base = NULL;
	b->base_n = 0;
}

static void	ft_print_format(t_struct *i, const char *format, int pos)
{
	i->specifier = format[pos];
	if (format[pos] == 'c')
		print_char(i);
	else if (format[pos] == 's')
		print_str(i);
	else if (format[pos] == 'p')
		print_ptr(i);
	else if (format[pos] == 'd' || format[pos] == 'i')
		print_nbr(i);
	else if (format[pos] == 'u')
		print_u(i);
	else if (format[pos] == 'x' || format[pos] == 'X' || format[pos] == 'o')
		print_hex(i);
	else if (format[pos] == '%')
		print_per(i);
}

static int	ft_check_flags(t_struct *b, const char *format, int pos)
{
	while (ft_strchr("0-+# ", format[pos]))
	{
		if (format[pos] == '0')
			b->zero = 1;
		if (format[pos] == '-')
			b->dash = 1;
		if (format[pos] == '+')
			b->plus = 1;
		if (format[pos] == '#')
			b->hash = 1;
		if (format[pos] == ' ')
			b->space = 1;
		pos++;
	}
	return (pos);
}

static int	ft_format(t_struct *b, const char *format, int pos)
{
	int	err_flag;
	int	start;

	start = pos;
	pos = ft_check_flags(b, format, pos);
	err_flag = ft_check(format, start);
	if (!err_flag && ft_strchr("cspdiuoxX%123456789.", format[pos]))
	{
		while (format[pos + 1] && !ft_strchr("cspdiuoxX%", format[pos]))
		{
			if (ft_isdigit(format[pos]) && !(b->point))
				pos = ft_width(b, format, pos);
			if (format[pos] == '.')
			{
				b->point = 1;
				pos = ft_decimal(b, format, pos + 1);
			}
			pos++;
		}
		ft_print_format(b, format, pos);
		return (pos);
	}
	pos = ft_err(b, format, pos);
	return (pos);
}

int	ft_printf(const char *format, ...)
{
	t_struct	*b;
	int			i;
	int			count;

	i = -1;
	count = 0;
	if (!format)
		return (-1);
	b = (t_struct *)malloc(sizeof(t_struct));
	if (!b)
		return (-1);
	init_struct(b);
	b->length = 0;
	va_start(b->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_format(b, format, i + 1);
		else
			count += write(1, &format[i], 1);
	}
	va_end(b->args);
	count += b->length;
	free(b);
	return (count);
}
