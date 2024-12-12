/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:17:24 by alanty            #+#    #+#             */
/*   Updated: 2024/04/21 14:17:26 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_putstr_fd("FDF fermé. Bye Bye!\n", 1);
	else if (exit_code == 1)
		ft_putstr_fd("FAUX! './fdf <file_path>'.\n", 1);
	else if (exit_code == 2)
		ft_putstr_fd("Impossible de lire le fichier.\n", 1);
	else if (exit_code == 3)
		ft_putstr_fd("Impossible d'initialiser FDF.\n", 1);
	else if (exit_code == 4)
		ft_putstr_fd("Impossible d'analyser la carte.\n", 1);
	else if (exit_code == 5)
		ft_putstr_fd("Impossible de créer l'image.\n", 1);
	else if (exit_code == 6)
		ft_putstr_fd("Impossible d'initialiser la caméra.\n", 1);
	else if (exit_code == 7)
		ft_putstr_fd("Impossible de rendre l'image.\n", 1);
	else if (exit_code == 8)
		ft_putstr_fd("Impossible d'initialiser les couleurs.\n", 1);
	exit(exit_code);
}
