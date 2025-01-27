/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:51:57 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:51:54 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					printfft_putaddress(void *format);
int					printfft_putunsigned(unsigned long n);
int					printfft_puthexa(unsigned int nb, int is_upper);
int					printfft_putchar(char c);
int					printfft_putstr(char *str);

int	printfft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		printfft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		printfft_putchar('-');
		len++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += printfft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		printfft_putchar(nb + 48);
		len++;
	}
	return (len);
}

long unsigned int	printfft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*printfft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
	{
		return (ptr);
	}
	return (NULL);
}

int	printfrec_print(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n > (printfft_strlen(base) - 1))
		len += printfrec_print(n / printfft_strlen(base), base);
	len += printfft_putchar(*(base + (n % printfft_strlen(base))));
	return (len);
}
