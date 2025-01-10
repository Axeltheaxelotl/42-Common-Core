/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:30:33 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:39:19 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Appends the NUL-terminated string src to the end of dst. It will append at
 * most size - strlen(dst) - 1 characters. It will then NUL-terminate, unless
 * size is less than strlen(dst).
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create.
 */

#include <stddef.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	dstlen;
	size_t	srclen;

	s = 0;
	if (!dst && size == 0)
		return (ft_strlen((char *)src));
	srclen = ft_strlen((char *)src);
	dstlen = ft_strlen(dst);
	d = dstlen;
	if (!dst && size == 0)
		return (srclen);
	if (size <= dstlen)
		return (size + srclen);
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (dstlen + srclen);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "world";
	char	dst[] = "hello, ";

	printf("%zu\n", ft_strlcat(dst, src, 13));
}
*/
