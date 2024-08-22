/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:25:49 by alanty            #+#    #+#             */
/*   Updated: 2024/03/05 15:11:17 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int num, size_t *compteur)
{
	if (num == -2147483648)
	{
		ft_putnbr_pf((num / 10), compteur);
		ft_putchar_pf('8', compteur);
	}
	else if (num < 0)
	{
		ft_putchar_pf('-', compteur);
		ft_putnbr_pf(-num, compteur);
	}
	else
	{
		if (num > 9)
			ft_putnbr_pf((num / 10), compteur);
		ft_putchar_pf(('0' + num % 10), compteur);
	}
}

int main()
{
	char teststr[] = "748521485652148521478596321478596524";
	printf("%s\n", teststr);
}
