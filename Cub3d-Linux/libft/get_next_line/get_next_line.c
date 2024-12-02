/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:35:02 by smasse            #+#    #+#             */
/*   Updated: 2024/09/05 15:41:43 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Reads the content of the file descriptor until a newline character is found.
 * 
 * @param fd The file descriptor to read from.
 * @param filedata The file data to store the content in.
 * @return The content of the file descriptor until a newline character is found.
 */

char	*get_next_line(int fd)
{
	static t_filedata	s_filedata[MAX_FILES] = {{NULL, 0}};
	size_t				pos;
	char				*content;
	size_t				start;
	char				*line;

	if (fd < 0 || fd >= MAX_FILES || BUFFER_SIZE < 1)
		return (NULL);
	if (s_filedata[fd].content == NULL)
		if (read_file(fd, &s_filedata[fd]) == NULL)
			return (NULL);
	pos = s_filedata[fd].position;
	content = s_filedata[fd].content;
	if (content[pos] == '\0')
	{
		free_filedata(&s_filedata[fd]);
		return (NULL);
	}
	start = pos;
	line = extract_line(content, &pos, start);
	s_filedata[fd].position = pos;
	if (content[pos] == '\0')
		free_filedata(&s_filedata[fd]);
	return (line);
}

char	*extract_line(char *content, size_t *pos, size_t start)
{
	size_t	len;
	char	*line;

	while (content[*pos] != '\n' && content[*pos] != '\0')
		(*pos)++;
	len = *pos - start;
	if (content[*pos] == '\n')
		line = (char *)malloc(len + 1 + 1);
	else
		line = (char *)malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strncpy(line, content + start, len);
	if (content[*pos] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	if (content[*pos] == '\n')
		(*pos)++;
	return (line);
}

size_t	read_content(int fd, char **buffer, size_t buffer_size)
{
	size_t	total_read;
	ssize_t	bytes_read;
	char	ch;

	total_read = 0;
	bytes_read = read(fd, &ch, 1);
	while (bytes_read > 0)
	{
		if (total_read + 1 >= buffer_size)
		{
			if (!expand_buffer(buffer, &buffer_size))
				return ((size_t) - 1);
		}
		(*buffer)[total_read++] = ch;
		if (ch == '\n')
			break ;
		bytes_read = read(fd, &ch, 1);
	}
	if (bytes_read < 0)
	{
		free(*buffer);
		return ((size_t) - 1);
	}
	return (total_read);
}

int	expand_buffer(char **buffer, size_t *buffer_size)
{
	char	*new_buffer;
	size_t	i;

	*buffer_size *= 2;
	new_buffer = (char *)malloc(*buffer_size + 1);
	if (new_buffer == NULL)
	{
		free(*buffer);
		return (0);
	}
	i = 0;
	while (i < *buffer_size / 2)
	{
		new_buffer[i] = (*buffer)[i];
		i++;
	}
	free(*buffer);
	*buffer = new_buffer;
	return (1);
}

char	*read_file(int fd, t_filedata *filedata)
{
	size_t	buffer_size;
	char	*buffer;
	size_t	total_read;

	buffer_size = BUFFER_SIZE;
	buffer = (char *)malloc(buffer_size + 1);
	if (buffer == NULL)
		return (NULL);
	total_read = read_content(fd, &buffer, buffer_size);
	if (total_read == (size_t) - 1)
		return (NULL);
	buffer[total_read] = '\0';
	filedata->content = buffer;
	filedata->position = 0;
	return (buffer);
}
