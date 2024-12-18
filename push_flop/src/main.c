/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:25:28 by alanty            #+#    #+#             */
/*   Updated: 2024/05/07 19:25:29 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialiser_pile(t_list **pile, int argc, char **argv)
{
	t_list	*nouveau;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		nouveau = ft_creer_maillon(ft_atoi(args[i]));
		ft_ajouter_derriere(pile, nouveau);
		i++;
	}
	index_pile(pile);
	if (argc == 2)
		liberer(args);
}

static void	trier_pile(t_list **pile_a, t_list **pile_b)
{
	if (ft_taille_liste(*pile_a) <= 5)
		trier_simple(pile_a, pile_b);
	else
		trier_base(pile_a, pile_b);
}

int	main(int argc, char **argv)
{
	t_list	**pile_a;
	t_list	**pile_b;

	if (argc < 2)
		return (-1);
	verifier_arguments(argc, argv);
	pile_a = (t_list **)malloc(sizeof(t_list));
	pile_b = (t_list **)malloc(sizeof(t_list));
	*pile_a = NULL;
	*pile_b = NULL;
	initialiser_pile(pile_a, argc, argv);
	if (est_trie(pile_a))
	{
		liberer_pile(pile_a);
		liberer_pile(pile_b);
		return (0);
	}
	trier_pile(pile_a, pile_b);
	liberer_pile(pile_a);
	liberer_pile(pile_b);
	return (0);
}
