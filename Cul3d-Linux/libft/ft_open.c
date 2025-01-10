/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:09:25 by smasse            #+#    #+#             */
/*   Updated: 2024/11/25 10:20:36 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_open(const char *path, int flags)
{
	int	fd;

	fd = open(path, flags);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	ft_close(int fd, char **l, int return_value)
{
	if (l)
		free(*l);
	close(fd);
	return (return_value);
}
