/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_nombre_non_signe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:48:43 by alanty            #+#    #+#             */
/*   Updated: 2024/02/28 13:15:02 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche_nombre_non_signe(unsigned int nombre, size_t *compteur)
{
	char	*str;

	str = conversion_nombre_vers_chaine(nombre, "0123456789");
	ft_putstr_pf(str, compteur);
	free(str);
}
