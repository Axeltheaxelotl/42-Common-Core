/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:41:29 by alanty            #+#    #+#             */
/*   Updated: 2024/03/28 15:11:10 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*s1;
	int		fd;

	printf("Buffer = %d\n", BUFFER_SIZE);
	fd = open ("t.txt", O_RDONLY);
	s1 = get_next_line(fd);
	printf("%s", s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
}
