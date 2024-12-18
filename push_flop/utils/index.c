/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/05/10 14:41:00 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*obtenir_prochain_min(t_list **pile)
{
	t_list	*tete;
	t_list	*min;
	int		a_min;

	min = NULL;
	a_min = 0;
	tete = *pile;
	if (tete)
	{
		while (tete)
		{
			if ((tete->index == -1) && (!a_min || tete->valeur < min->valeur))
			{
				min = tete;
				a_min = 1;
			}
			tete = tete->suivant;
		}
	}
	return (min);
}

void	index_pile(t_list **pile)
{
	t_list	*tete;
	int		index;

	index = 0;
	tete = obtenir_prochain_min(pile);
	while (tete)
	{
		tete->index = index;
		index++;
		tete = obtenir_prochain_min(pile);
	}
}
