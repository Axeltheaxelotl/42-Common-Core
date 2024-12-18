/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:02:18 by alanty            #+#    #+#             */
/*   Updated: 2024/05/08 16:03:16 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **pile_a, t_list **pile_b)
{
	if (pousser(pile_a, pile_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **pile_a, t_list **pile_b)
{
	if (pousser(pile_b, pile_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	sa(t_list **pile_a)
{
	if (echanger(pile_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **pile_b)
{
	if (echanger(pile_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **pile_a, t_list **pile_b)
{
	if ((ft_taille_liste(*pile_a) < 2) || (ft_taille_liste(*pile_b) < 2))
		return (-1);
	echanger(pile_a);
	echanger(pile_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
