/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:08:00 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 18:12:58 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Outputs the string s to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */

size_t	ft_strlen(const char *s);

void	ft_putstr_fd(const char *s, int fd)
{
	if (s)
	{
		(void)!write(fd, s, ft_strlen(s));
	}
}
