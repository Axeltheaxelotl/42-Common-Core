/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:27:52 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 14:02:32 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory. The memory is set to zero.
 *
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return The pointer to the allocated memory.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
