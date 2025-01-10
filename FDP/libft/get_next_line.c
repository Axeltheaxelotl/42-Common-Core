/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:28:20 by alanty            #+#    #+#             */
/*   Updated: 2024/03/22 18:48:42 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remplir_liste(t_liste **lst, t_liste *dernier, int fd)
{
	char	*buffer;
	int		bytes_lus;
	int		i;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (!obtenir_nl(*lst))
	{
		bytes_lus = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lus <= 0)
			break ;
		i = 0;
		if (!*lst)
			*lst = ft_lstnew(buffer[i++]);
		if (!dernier)
			dernier = *lst;
		while (i < bytes_lus)
		{
			dernier->suivant = ft_lstnew(buffer[i]);
			dernier = dernier->suivant;
			i++;
		}
	}
	free(buffer);
}

char	*liste_vers_chaine(t_liste **lst)
{
	char	*ligne;
	t_liste	*tmp;
	int		longeur;
	int		i;

	if (*lst == NULL)
		return (NULL);
	longeur = obtenir_longeur(*lst, 0);
	ligne = (char *)malloc(sizeof(char) * (longeur + 1));
	i = 0;
	while (i < longeur)
	{
		ligne[i] = (*lst)->lettre;
		tmp = *lst;
		*lst = (*lst)->suivant;
		free(tmp);
		i++;
	}
	ligne[longeur] = '\0';
	return (ligne);
}

char	*get_next_line(int fd)
{
	static t_liste	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remplir_liste(&lst, dernier(lst), fd);
	return (liste_vers_chaine(&lst));
}
