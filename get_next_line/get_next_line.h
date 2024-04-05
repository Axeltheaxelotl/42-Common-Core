/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:27:06 by alanty            #+#    #+#             */
/*   Updated: 2024/03/14 14:16:06 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *thestring);
char	*strjoint(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int rechercheChar);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementcompter, size_t elementsize);

#endif
