/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:02:56 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 14:25:13 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Outputs the character c to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	(void)!write(fd, &c, 1);
}
