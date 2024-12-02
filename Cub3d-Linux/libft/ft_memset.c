/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:19:35 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 15:06:17 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Fills the first n bytes of the memory area pointed to by s with the constant
 * byte c.
 *
 * @param s The memory area to fill.
 * @param c The constant byte to fill the memory area with.
 * @param length The number of bytes to fill.
 * @return The memory area s.
 */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t length)
{
	unsigned char	*a;

	a = s;
	while (length > 0)
	{
		*a = c;
		a++;
		length--;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "test test fbu";
	int		c;
	size_t	length;

	//int num[] = {25, 50, 75, 100};
	c = 'l';
	length = 2;
	printf("%s\n", (char *)ft_memset(s, c, length));
	return (0);
}
*/
