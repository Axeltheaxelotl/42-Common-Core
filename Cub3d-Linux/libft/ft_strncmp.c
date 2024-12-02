/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:56:08 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 15:05:01 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Compares the two strings s1 and s2, but at most n bytes are compared.
 * Because strncmp() is designed for comparing strings rather than binary data,
 * characters that appear after a '\0' character are not compared.
 * 
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	if (*s1 == *s2)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>
int main()
{
	const char *s1 = "1234";
	const char *s2 = "1235";
	printf("%d\n", ft_strncmp(s1, s2, 4));
}
*/
