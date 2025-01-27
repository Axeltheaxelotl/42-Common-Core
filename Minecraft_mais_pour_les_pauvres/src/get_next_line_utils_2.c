/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:52:28 by alanty            #+#    #+#             */
/*   Updated: 2025/01/09 17:52:30 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_copy(char **line, char **buff);
int	ft_eof(int ret, char **buff, char **line);
int	ft_free_buff(char **buff, t_recup *recup);

int	ft_allocate_buff(char **buff)
{
	*buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!*buff)
		return (-1);
	return (0);
}

int	ft_read_and_copy(int fd, char **line, char **buff)
{
	int	ret;

	ret = read(fd, *buff, BUFFER_SIZE);
	while (ret > 0)
	{
		(*buff)[ret] = '\0';
		if (!ft_copy(line, buff))
			return (1);
		ret = read(fd, *buff, BUFFER_SIZE);
	}
	return (ret);
}

int	get_next_line(int fd, char **line, t_recup *recup)
{
	static char	*buff = NULL;
	int			ret;

	if (ft_free_buff(&buff, recup) == 1)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	ret = 1;
	if (buff)
		ret = ft_copy(line, &buff);
	if (ret == 0)
		return (1);
	if (!buff)
		if (ft_allocate_buff(&buff) == -1)
			return (-1);
	ret = ft_read_and_copy(fd, line, &buff);
	if (ret <= 0)
		return (ft_eof(ret, &buff, line));
	return (1);
}
