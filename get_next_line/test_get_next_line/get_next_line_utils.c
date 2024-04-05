/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:29:24 by alanty            #+#    #+#             */
/*   Updated: 2024/03/21 18:29:25 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_liste	*ft_lstnew(char lettre)
{
	t_liste	*lst;

	lst = (t_liste *)malloc(sizeof(t_liste));
	if (!lst)
		return (NULL);
	lst->lettre = lettre;
	lst->suivant = NULL;
	return (lst);
}

t_liste	*dernier(t_liste *lst)
{
	if (!lst)
		return (NULL);
	while (lst->suivant)
		lst = lst->suivant;
	return (lst);
}

int	obtenir_nl(t_liste *lst)
{
	while (lst && lst->lettre != '\n')
		lst = lst->suivant;
	return (lst != NULL);
}

int	obtenir_longeur(t_liste *lst, int i)
{
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		if (lst->lettre == '\n')
			return (i);
		lst = lst->suivant;
	}
	return (i);
}
