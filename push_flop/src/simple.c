/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:26:05 by alanty            #+#    #+#             */
/*   Updated: 2024/05/07 19:26:07 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	obtenir_min(t_list **pile, int valeur)
{
	t_list	*tete;
	int		min;

	tete = *pile;
	min = tete->index;
	while (tete->suivant)
	{
		tete = tete->suivant;
		if ((tete->index < min) && tete->index != valeur)
			min = tete->index;
	}
	return (min);
}

static void	trier4(t_list **pile_a, t_list **pile_b)
{
	int	distance;

	if (est_trie(pile_a))
		return ;
	distance = obtenir_distance(pile_a, obtenir_min(pile_a, -1));
	if (distance == 1)
		ra(pile_a);
	else if (distance == 2)
	{
		ra(pile_a);
		ra(pile_a);
	}
	else if (distance == 3)
		rra(pile_a);
	if (est_trie(pile_a))
		return ;
	pb(pile_a, pile_b);
	trier3(pile_a);
	pa(pile_a, pile_b);
}

void	trier5(t_list **pile_a, t_list **pile_b)
{
	int	distance;

	distance = obtenir_distance(pile_a, obtenir_min(pile_a, -1));
	if (distance == 1)
		ra(pile_a);
	else if (distance == 2)
	{
		ra(pile_a);
		ra(pile_a);
	}
	else if (distance == 3)
	{
		rra(pile_a);
		rra(pile_a);
	}
	else if (distance == 4)
		rra(pile_a);
	if (est_trie(pile_a))
		return ;
	pb(pile_a, pile_b);
	trier4(pile_a, pile_b);
	pa(pile_a, pile_b);
}

void	trier_simple(t_list **pile_a, t_list **pile_b)
{
	int	taille;

	if (est_trie(pile_a) || ft_taille_liste(*pile_a) == 0
		|| ft_taille_liste(*pile_a) == 1)
		return ;
	taille = ft_taille_liste(*pile_a);
	if (taille == 2)
		sa(pile_a);
	else if (taille == 3)
		trier3(pile_a);
	else if (taille == 4)
		trier4(pile_a, pile_b);
	else if (taille == 5)
		trier5(pile_a, pile_b);
}
