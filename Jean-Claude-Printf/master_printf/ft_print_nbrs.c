/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:01:24 by smasse            #+#    #+#             */
/*   Updated: 2024/09/11 19:18:36 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_base(long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

void	ft_putnum_base(long int n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n / base_len)
	{
		ft_putnum_base(n / base_len, base);
	}
	ft_putchar(base[n % base_len]);
}

static int	ft_print_nbr_util(t_struct *item, int len, long int n)
{
	if (!n && !item->precision && item->point)
		len--;
	if (item->space && n >= 0 && !item->plus)
		len += write(1, " ", 1);
	if ((item->plus || n < 0))
		len++;
	if ((item->width && !item->dash) && (!item->zero || item->point))
		ft_align(item, len);
	if (item->plus && n >= 0)
		write(1, "+", 1);
	if (n < 0)
		ft_putchar('-');
	if (((item->zero && !item->dash) && !(item->point))
		|| (item->precision > item->baselen))
		pad_zeros(item, len);
	return (len);
}

void	print_nbr(t_struct *item)
{
	long int	n;
	int			len;

	n = va_arg(item -> args, int);
	item->baselen = ft_len_base(n, 10);
	len = item->baselen;
	len = ft_print_nbr_util(item, len, n);
	if (n < 0)
		n = -n;
	if (n != 0 || (n == 0 && !(item->point && !item->precision)))
		ft_putnum_base(n, "0123456789");
	if (item->dash)
		ft_left_align(item, len);
	item->length += len;
	init_struct(item);
}

void	print_u(t_struct *item)
{
	long int	n;
	int			len;

	n = va_arg(item -> args, unsigned int);
	item->baselen = ft_len_base(n, 10);
	len = item->baselen;
	len = ft_print_nbr_util(item, len, n);
	if (n != 0 || (n == 0 && !(item->point && !item->precision)))
		ft_putnum_base(n, "0123456789");
	if (item->dash)
		ft_left_align(item, len);
	item->length += len;
	init_struct(item);
}
