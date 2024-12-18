/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triee_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:29:32 by alanty            #+#    #+#             */
/*   Updated: 2024/05/11 13:15:04 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operation(t_list **pile_a, int condition)
{
	if (condition == 1)
	{
		ra(pile_a);
		sa(pile_a);
		rra(pile_a);
	}
	else if (condition == 2)
		sa(pile_a);
	else if (condition == 3)
		rra(pile_a);
	else if (condition == 4)
		ra(pile_a);
	else
	{
		sa(pile_a);
		rra(pile_a);
	}
}

void	determine_et_execute(t_list **pile_a, int min, int min_suivant)
{
	t_list	*tete;

	tete = *pile_a;
	if (tete->index == min)
	{
		if (tete->suivant->index != min_suivant)
			execute_operation(pile_a, 1);
	}
	else if (tete->index == min_suivant)
	{
		if (tete->suivant->index == min)
			execute_operation(pile_a, 2);
		else
			execute_operation(pile_a, 3);
	}
	else
	{
		if (tete->suivant->index == min)
			execute_operation(pile_a, 4);
		else
			execute_operation(pile_a, 5);
	}
}

void	trier3(t_list **pile_a)
{
	int		min;
	int		min_suivant;

	if (est_trie(pile_a))
		return ;
	min = obtenir_min(pile_a, -1);
	min_suivant = obtenir_min(pile_a, min);
	determine_et_execute(pile_a, min, min_suivant);
}
