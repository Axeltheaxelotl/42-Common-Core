/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:48:00 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 15:06:45 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies n bytes from memory area src to memory area dest. The memory areas
 * must not overlap.
 *
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param len The number of bytes to copy.
 * @return The original value of dest.
 */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	const char		*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[20];

	memcpy(dest, src, strlen(src) + 1);
	printf("Source string: %s\n", src);
	printf("Destination string: %s\n", dest);
	return (0);
}
*/
