/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:41:47 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:52:26 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int		printfft_putchar(char c);
int		printfft_putstr(char *str);
int		printfft_putnbr(int nb);
int		printfft_puthexa(unsigned int nb, int is_upper);
int		printfft_putaddress(void *format);
int		printfft_putunsigned(unsigned long n);
char	*printfft_strchr(const char *s, int c);

int	printfft_format(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (printfft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (printfft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (printfft_putnbr((va_arg(args, int))));
	else if (format == 'x')
		return (printfft_puthexa(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (printfft_puthexa(va_arg(args, unsigned int), 1));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (printfft_putstr("(nil)"));
		return (printfft_putaddress(ptr));
	}
	else if (format == 'u')
		return (printfft_putunsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (printfft_putchar('%'));
	else
		return (-1);
}

/**
 * @brief	Outputs a formatted string.
 *
 * @param	str	The string to output.
 * @param	...	The arguments to format.
 *
 * @return	The number of characters output.
 */

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%' && printfft_strchr("cspdiuxX%", *(str + i + 1)))
		{
			length += printfft_format(args, *(str + i + 1));
			i++;
		}
		else
			length += printfft_putchar(*(str + i));
		i++;
	}
	va_end(args);
	return (length);
}
