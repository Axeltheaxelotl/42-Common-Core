/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:39:32 by smasse            #+#    #+#             */
/*   Updated: 2024/05/31 15:41:12 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_FILES 4096

typedef struct s_filedata
{
	char	*content;
	size_t	position;
}			t_filedata;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*extract_line(char *content, size_t *pos, size_t start);
size_t		read_content(int fd, char **buffer, size_t buffer_size);
int			expand_buffer(char **buffer, size_t *buffer_size);
char		*read_file(int fd, t_filedata *filedata);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
void		free_filedata(t_filedata *filedata);
int			expand_buffer(char **buffer, size_t *buffer_size);
char		*read_file(int fd, t_filedata *filedata);

#endif // GET_NEXT_LINE_H