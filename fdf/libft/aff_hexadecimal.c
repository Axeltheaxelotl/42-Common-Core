/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_hexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:51:32 by alanty            #+#    #+#             */
/*   Updated: 2024/02/28 13:24:39 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aff_hexadecimal(unsigned int nombre, size_t *compteur, char *base)
{
	char	*str_hexa;

	str_hexa = conversion_nb_ch(nombre, base);
	ft_putstr_pf(str_hexa, compteur);
	free(str_hexa);
}
