/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:06 by alanty            #+#    #+#             */
/*   Updated: 2024/05/08 15:23:48 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **pile_a)
{
	if (rotation_inverse(pile_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **pile_b)
{
	if (rotation_inverse(pile_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **pile_a, t_list **pile_b)
{
	if ((ft_taille_liste(*pile_a) < 2) || (ft_taille_liste(*pile_b) < 2))
		return (-1);
	rotation_inverse(pile_a);
	rotation_inverse(pile_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	ra(t_list **pile_a)
{
	if (rotation(pile_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **pile_b)
{
	if (rotation(pile_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}
