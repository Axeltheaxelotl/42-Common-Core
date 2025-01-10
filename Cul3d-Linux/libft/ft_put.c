/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:31:28 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 19:43:36 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long unsigned int	printfft_strlen(const char *str);
int					printfrec_print(unsigned long n, const char *base);

int	printfft_putchar(char c)
{
	(void)!write(1, &c, 1);
	return (1);
}

int	printfft_putstr(char *str)
{
	int	i;

	if (!str)
		return (printfft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		printfft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	printfft_puthexa(unsigned int nb, int is_upper)
{
	int		i;
	int		digit;
	char	output[9];

	i = 8;
	output[i] = '\0';
	if (nb == 0)
	{
		output[--i] = '0';
	}
	while (nb > 0)
	{
		digit = nb % 16;
		if (digit < 10)
			output[--i] = '0' + digit;
		else
		{
			if (is_upper)
				output[--i] = 'A' + (digit - 10);
			else
				output[--i] = 'a' + (digit - 10);
		}
		nb /= 16;
	}
	return (printfft_putstr(output + i));
}

int	printfft_putunsigned(unsigned long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n > (printfft_strlen(base) - 1))
		len += printfft_putunsigned(n / printfft_strlen(base));
	len += printfft_putchar(*(base + (n % printfft_strlen(base))));
	return (len);
}

int	printfft_putaddress(void *format)
{
	unsigned long	n;
	const char		*base;
	int				len;

	n = (unsigned long)format;
	base = "0123456789abcdef";
	len = printfft_putstr("0x");
	len += printfrec_print(n, base);
	return (len);
}
