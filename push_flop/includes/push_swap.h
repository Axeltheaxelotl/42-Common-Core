/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:24:26 by alanty            #+#    #+#             */
/*   Updated: 2024/05/10 14:45:21 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				valeur;
	int				index;
	struct s_list	*suivant;
}				t_list;

t_list	*ft_creer_maillon(int valeur);
t_list	*ft_dernier_maillon(t_list *tete);
void	ft_ajouter_devant(t_list **pile, t_list *nouveau);
void	ft_ajouter_derriere(t_list **pile, t_list *nouveau);
void	imprimer_liste(t_list *tete);
int		ft_taille_liste(t_list *tete);
void	erreur(char *msg);
void	verifier_arguments(int argc, char **argv);
int		est_trie(t_list **pile);
int		obtenir_distance(t_list **pile, int index);
void	placer_en_haut(t_list **pile, int distance);
void	liberer_pile(t_list **pile);
void	liberer(char **str);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	index_pile(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		echanger(t_list **pile);
int		pousser(t_list **pile_vers, t_list **pile_de);
int		rotation(t_list **pile);
int		rotation_inverse(t_list **pile);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **pile_a, t_list **pile_b);
int		pa(t_list **pile_a, t_list **pile_b);
int		pb(t_list **pile_a, t_list **pile_b);
int		ra(t_list **pile_a);
int		rb(t_list **pile_b);
int		rr(t_list **pile_a, t_list **pile_b);
int		rra(t_list **pile_a);
int		rrb(t_list **pile_b);
int		rrr(t_list **pile_a, t_list **pile_b);
void	trier_simple(t_list **pile_a, t_list **pile_b);
void	trier_base(t_list **pile_a, t_list **pile_b);
void	determine_and_execute(t_list **pile_a, int min, int next_min);
void	execute_operation(t_list **pile_a, int condition);
void	trier3(t_list **pile_a);
int		obtenir_min(t_list **pile, int valeur);

#endif
