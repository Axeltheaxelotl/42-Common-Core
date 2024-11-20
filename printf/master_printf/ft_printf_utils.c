/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:01:08 by smasse            #+#    #+#             */
/*   Updated: 2024/11/06 21:06:03 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	pad_zeros(t_struct *item, int len)
{
	int	i;

	i = 0;
	if (item->precision > item->baselen)
	{
		while (i < (item->precision - item->baselen))
		{
			item->length += write(1, "0", 1);
			i++;
		}
	}
	else if (!(item->precision > item->baselen))
	{
		while (i < (item->width - len))
		{
			item->length += write(1, "0", 1);
			i++;
		}
	}
}

void	ft_align(t_struct *item, int len)
{
	int	i;

	i = 0;
	if (item->precision > item->baselen)
	{
		while (i < (item->width - (item->precision - item->baselen) - len))
		{
			item->length += write(1, " ", 1);
			i++;
		}
	}
	else if (!(item->precision > item->baselen))
	{
		while (i < (item->width - len))
		{
			item->length += write(1, " ", 1);
			i++;
		}
	}
}

void	ft_left_align(t_struct *item, int len)
{
	int	i;

	i = 0;
	if (item->precision > item->baselen)
	{
		while (i < (item->width - (item->precision - item->baselen) - len))
		{
			item->length += write(1, " ", 1);
			i++;
		}
	}
	else if (!(item->precision > item->baselen))
	{
		while (i < (item->width - len))
		{
			item -> length += write(1, " ", 1);
			i++;
		}
	}
}
