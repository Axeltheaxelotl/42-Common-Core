/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:40:53 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:36:50 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Copies up to size - 1 characters from the NUL-terminated string src to dst,
 * NUL-terminating the result.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create.
 */

#include <stddef.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

//cc -Wall -Wextra -Werror -lbsd ft_strlcat.c ft_strlen.c -o strlcpymain
int	main(void) {
	const char *src = "Hello, world!";
	char dst[20];
	size_t result = ft_strlcpy(dst, src, sizeof(dst));

	printf("Copied string: '%s'\n", dst);
	printf("Return value: %zu\n", result);

	return (0);
}
*/
