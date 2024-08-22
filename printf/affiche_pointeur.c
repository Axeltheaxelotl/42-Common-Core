/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_pointeur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:43:59 by alanty            #+#    #+#             */
/*   Updated: 2024/02/28 19:11:55 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	affiche_pointeur(void *ptr, size_t *compteur)
{
	unsigned long	ptr_address;
	char			*ptr_str;

	if (ptr == NULL)
	{
		ft_putstr_pf("(nil)", compteur);
		return ;
	}
	ptr_address = (unsigned long)ptr;
	ft_putstr_pf("0x", compteur);
	ptr_str = conversion_nombre_vers_chaine(ptr_address, HEX_LOW_BASE);
	ft_putstr_pf(ptr_str, compteur);
	free(ptr_str);
}
