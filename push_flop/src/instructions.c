/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:25:17 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 11:48:23 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	echanger(t_list **pile)
{
	t_list	*tete;
	t_list	*suivant;
	int		tmp_val;
	int		tmp_index;

	if (ft_taille_liste(*pile) < 2)
		return (-1);
	tete = *pile;
	suivant = tete->suivant;
	if (!tete && !suivant)
		erreur("Erreur lors de l'échange !");
	tmp_val = tete->valeur;
	tmp_index = tete->index;
	tete->valeur = suivant->valeur;
	tete->index = suivant->index;
	suivant->valeur = tmp_val;
	suivant->index = tmp_index;
	return (0);
}

int	pousser(t_list **pile_vers, t_list **pile_de)
{
	t_list	*tmp;
	t_list	*tete_vers;
	t_list	*tete_de;

	if (ft_taille_liste(*pile_de) == 0)
		return (-1);
	tete_vers = *pile_vers;
	tete_de = *pile_de;
	tmp = tete_de;
	tete_de = tete_de->suivant;
	*pile_de = tete_de;
	if (!tete_vers)
	{
		tete_vers = tmp;
		tete_vers->suivant = NULL;
		*pile_vers = tete_vers;
	}
	else
	{
		tmp->suivant = tete_vers;
		*pile_vers = tmp;
	}
	return (0);
}

int	rotation(t_list **pile)
{
	t_list	*tete;
	t_list	*queue;

	if (ft_taille_liste(*pile) < 2)
		return (-1);
	tete = *pile;
	queue = ft_dernier_maillon(tete);
	*pile = tete->suivant;
	tete->suivant = NULL;
	queue->suivant = tete;
	return (0);
}

int	rotation_inverse(t_list **pile)
{
	t_list	*tete;
	t_list	*queue;

	if (ft_taille_liste(*pile) < 2)
		return (-1);
	tete = *pile;
	queue = ft_dernier_maillon(tete);
	while (tete)
	{
		if (tete->suivant->suivant == NULL)
		{
			tete->suivant = NULL;
			break ;
		}
		tete = tete->suivant;
	}
	queue->suivant = *pile;
	*pile = queue;
	return (0);
}

int	rr(t_list **pile_a, t_list **pile_b)
{
	if ((ft_taille_liste(*pile_a) < 2) || (ft_taille_liste(*pile_b) < 2))
		return (-1);
	rotation(pile_a);
	rotation(pile_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
