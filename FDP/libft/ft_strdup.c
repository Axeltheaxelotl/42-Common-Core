/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:51:26 by alanty            #+#    #+#             */
/*   Updated: 2024/02/21 19:31:56 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	*src = "Hello, world!";
	char	*duplicate;
	
	duplicate = ft_strdup(src);
	if (duplicate == NULL)
	{	
		fprintf(stderr, "Allocation error\n");
		return 1;
	}
	
	printf("Original string: %s\n", src);
	printf("Duplicate string: %s\n", duplicate);
	
	free(duplicate);
	return 0;
}
*/
