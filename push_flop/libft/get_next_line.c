/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:33:14 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 19:07:10 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_new_line(char **stack, char **line)
{
	char		*tmp_stack;
	char		*strchr_stack;
	int			i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
	{
		if (!strchr_stack[i++])
			return (0);
	}
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = *stack;
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static void	add_heap_to_static(char **s, char *buf)
{
	char		*tmp;

	tmp = *s;
	if (!tmp)
		*s = ft_strdup(buf);
	else
	{
		*s = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
}

static	int	ft_exit(char **line)
{
	*line = NULL;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[1025];
	char		heap[2];
	int			ret;

	if (!line || fd < 0 || fd >= 1025 || (read(fd, s[fd], 0) < 0))
		return (-1);
	ret = read(fd, heap, 1);
	while (ret > 0)
	{
		heap[ret] = '\0';
		add_heap_to_static(&s[fd], heap);
		if (verify_new_line(&s[fd], line))
			return (1);
		ret = read(fd, heap, 1);
	}
	if (!s[fd] || s[fd][0] == '\0')
		return (ft_exit(line));
	if (s[fd])
		if (verify_new_line(&(s[fd]), line))
			return (1);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (1);
}
