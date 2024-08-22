/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:29:13 by alanty            #+#    #+#             */
/*   Updated: 2024/03/21 18:29:14 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_liste
{
	char			lettre;
	struct s_liste	*suivant;
}	t_liste;

t_liste	*ft_lstnew(char lettre);
char	*obtenir_ligne_suivante(int fd);
char	*liste_vers_chaine(t_liste **lst);
void	remplir_liste(t_liste **lst, t_liste *dernier, int fd);
int		obtenir_nl(t_liste *lst);
int		obtenir_longeur(t_liste *lst, int i);
t_liste	*dernier(t_liste *lst);
#endif
