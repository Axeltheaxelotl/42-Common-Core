/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:36:14 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 15:05:28 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies len bytes from string src to string dst. The two strings may overlap;
 * the copy is always done in a non-destructive manner.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param len The number of bytes to copy.
 * @return The original value of dst.
 */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char		*d;
	const char	*s;
	char		*endd;
	const char	*ends;

	if (dst == NULL && src == NULL && len > 0)
		return (NULL);
	d = dst;
	s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		ends = s + (len - 1);
		endd = d + (len - 1);
		while (len--)
			*endd-- = *ends--;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	printf("Before _ft_memmove:\n");
	printf("sResult: ");
	for (size_t i = 0; i < sizeof(sResult); i++) {
		printf("%d ", sResult[i]);
	}
	printf("\n");
	ft_memmove(sResult + 1, sResult, 2);
	printf("After _ft_memmove:\n");
	printf("sResult: ");
	for (size_t i = 0; i < sizeof(sResult); i++) {
		printf("%d ", sResult[i]);
	}
	printf("\n");
	return (0);
}
*/
