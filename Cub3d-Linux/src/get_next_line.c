/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:28 by alanty            #+#    #+#             */
/*   Updated: 2025/01/09 17:50:12 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_copy(char **line, char **buff)
{
	int		start;
	char	*temp;
	char	*line_temp;

	start = ft_check(*buff);
	if (start >= 0)
	{
		temp = ft_substr(*buff, 0, start);
		line_temp = *line;
		*line = ft_strjoin(*line, temp);
		free(temp);
		free(line_temp);
		*buff = ft_subbuff(*buff, start + 1, ft_strlen(*buff) - start);
		return (0);
	}
	if (*line)
		temp = *line;
	else
		temp = NULL;
	*line = ft_strjoin(*line, *buff);
	free(temp);
	return (1);
}

int	ft_eof(int ret, char **buff, char **line)
{
	if (ret == -1)
		return (-1);
	free(*buff);
	*buff = NULL;
	if (*line == NULL)
	{
		*line = malloc(sizeof(char) * 1);
		*line[0] = 0;
	}
	return (0);
}

int	ft_free_buff(char **buff, t_recup *recup)
{
	if (recup->erreur == 2 && *buff)
	{
		free(*buff);
		return (1);
	}
	return (0);
}
