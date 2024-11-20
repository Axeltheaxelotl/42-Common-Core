/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:01:18 by smasse            #+#    #+#             */
/*   Updated: 2024/09/15 21:13:54 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_base_p(unsigned long int n, int base)
{
	int	len;

	len = 0;
	if (!n)
		len = 5;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static void	ft_putnum_base_p(unsigned long int n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n / base_len)
	{
		ft_putnum_base_p(n / base_len, base);
	}
	ft_putchar(base[n % base_len]);
}

static void	ft_p_helper(t_struct *item, unsigned long p)
{
	if (item->plus && p)
		write(1, "+", 1);
	if (p)
		write(1, "0x", 2);
	if (!p)
		write(1, "(nil)", 5);
}

void	print_ptr(t_struct *item)
{
	int				len;
	unsigned long	p;

	p = (unsigned long)va_arg(item->args, void *);
	item->baselen = ft_len_base_p(p, 16);
	len = item->baselen;
	if (p)
		len += 2;
	if (item->plus && p)
		len++;
	if (!p)
		item->baselen = item->precision;
	if ((item->width && !item->dash) && (!item->zero || item->point || !p))
		ft_align(item, len);
	ft_p_helper(item, p);
	if ((item->zero && !item->dash && !item->point && p)
		|| ((item->precision > item->baselen) && p))
		pad_zeros(item, len);
	if (p)
		ft_putnum_base_p(p, "0123456789abcdef");
	if (item->dash)
		ft_left_align(item, len);
	item -> length += len;
	init_struct(item);
}
