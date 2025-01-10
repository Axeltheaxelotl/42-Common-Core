/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:11:42 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 17:38:34 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Outputs the string s to the given file descriptor, followed by a newline.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */

#include <unistd.h>

size_t	ft_strlen(const char *s);

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	(void)!write(fd, s, ft_strlen(s));
	(void)!write(fd, "\n", 1);
}
