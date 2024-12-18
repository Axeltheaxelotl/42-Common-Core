/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:30:12 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 12:30:14 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*letter;
	int		i;

	letter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			letter = (char *)(str + i);
			return (letter);
		}
		i++;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}
