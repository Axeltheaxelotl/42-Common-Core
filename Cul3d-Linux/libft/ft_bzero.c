/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:21:49 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 19:43:43 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

/**
 * Sets the first n bytes of the memory area pointed to by s to zero.
 *
 * @param s The memory area to zero.
 * @param n The number of bytes to zero.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			*word;
	const size_t	zero_word = 0;

	a = s;
	while (n > 0 && ((uintptr_t)a & (sizeof(size_t) - 1)) != 0)
	{
		*a++ = 0;
		n--;
	}
	word = (size_t *)a;
	while (n >= sizeof(size_t))
	{
		*word++ = zero_word;
		n -= sizeof(size_t);
	}
	a = (unsigned char *)word;
	while (n > 0)
	{
		*a++ = 0;
		n--;
	}
}

/*int main()
{
	char	buffer[10];

	printf("Before bzero: \"%s\"\n", buffer);
	zero(buffer, sizeof(buffer));
	ft_bzero(buffer, sizeof(buffer));
	printf("After bzero: \"%s\"\n", buffer);
	return (0);
}
*/
