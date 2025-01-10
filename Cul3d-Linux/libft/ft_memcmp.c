/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:52:50 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 16:22:45 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Compares byte string s1 against byte string s2. Both strings are assumed to
 * be n bytes long.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/*
#include <stddef.h>
#include <stdio.h>

int	main(void)
{
	char			s2[] = {0, 0, 127, 0};
	char			s3[] = {0, 0, 42, 0};
	unsigned int	n;

	//const unsigned char s1[] = "hello";
	//const unsigned char s2[] = "gorld";
	n = 4;
	if (ft_memcmp(s2, s3, n) == 0)
	printf("strings are equal");
	else
	printf("the difference is %d\n", ft_memcmp(s2, s3, n));
	return(0);
}
*/
