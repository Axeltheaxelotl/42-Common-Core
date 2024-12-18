/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:21:55 by alanty            #+#    #+#             */
/*   Updated: 2024/05/11 11:22:34 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ajouter_derriere(t_list **pile, t_list *nouveau)
{
	t_list	*n;

	if (*pile)
	{
		n = ft_dernier_maillon(*pile);
		n->suivant = nouveau;
		nouveau->suivant = NULL;
	}
	else
	{
		*pile = nouveau;
		(*pile)->suivant = NULL;
	}
}

void	placer_en_haut(t_list **pile, int distance)
{
	t_list	*tete;
	int		tmp;

	tete = *pile;
	if (distance == 0)
		return ;
	tmp = ft_taille_liste(tete) - distance;
	if (distance <= (ft_taille_liste(tete) / 2))
	{
		while (distance-- > 0)
			ra(pile);
	}
	else
	{
		while (tmp-- > 0)
			rra(pile);
	}
}
