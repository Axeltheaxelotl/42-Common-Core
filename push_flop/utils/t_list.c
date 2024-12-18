/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/05/08 14:51:19 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_creer_maillon(int valeur)
{
	t_list	*nouveau;

	nouveau = (t_list *) malloc(sizeof(*nouveau));
	if (!nouveau)
		return (NULL);
	nouveau->valeur = valeur;
	nouveau->index = -1;
	nouveau->suivant = NULL;
	return (nouveau);
}

void	ft_ajouter_devant(t_list **pile, t_list *nouveau)
{
	nouveau->suivant = *pile;
	*pile = nouveau;
}

t_list	*ft_dernier_maillon(t_list *tete)
{
	t_list	*tmp;

	tmp = tete;
	while (tmp->suivant)
	{
		tmp = tmp->suivant;
		if (tmp->suivant == NULL)
			return (tmp);
	}
	return (tmp);
}

int	ft_taille_liste(t_list *tete)
{
	size_t	i;
	t_list	*tmp;

	tmp = tete;
	i = 0;
	while (tmp)
	{
		tmp = tmp->suivant;
		i++;
	}
	return (i);
}

void	imprimer_liste(t_list *tete)
{
	t_list	*tmp;

	tmp = tete;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->valeur, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->suivant;
	}
}
