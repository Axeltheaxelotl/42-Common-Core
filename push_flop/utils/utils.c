/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/05/10 14:43:58 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	erreur(char *message)
{
	ft_putendl_fd(message, 1);
	exit(0);
}

void	liberer(char **chaines)
{
	int	i;

	i = 0;
	while (chaines[i])
		i++;
	while (i >= 0)
	{
		free(chaines[i]);
		i--;
	}
}

int	est_trie(t_list **pile)
{
	t_list	*tete;

	tete = *pile;
	while (tete && tete->suivant)
	{
		if (tete->valeur > tete->suivant->valeur)
			return (0);
		tete = tete->suivant;
	}
	return (1);
}

int	obtenir_distance(t_list **pile, int index)
{
	t_list	*tete;
	int		distance;

	tete = *pile;
	distance = 0;
	while (tete)
	{
		if (tete->index == index)
			break ;
		distance++;
		tete = tete->suivant;
	}
	return (distance);
}

void	liberer_pile(t_list **pile)
{
	t_list	*tete;
	t_list	*tmp;

	tete = *pile;
	while (tete)
	{
		tmp = tete;
		tete = tete->suivant;
		free(tmp);
	}
	free(pile);
}
