/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:14:07 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 21:06:21 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl(int fd, char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	*line = get_next_line(fd);
	if (*line)
		return (1);
	return (0);
}
