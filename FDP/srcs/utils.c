/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:51:34 by alanty            #+#    #+#             */
/*   Updated: 2024/04/05 12:51:36 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//Fonction qui renvoie la valeur absolue d'un nombre flottant
float	absolute(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

//Fonction qui renvoie le maximum entre deux nombres flottants
float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

//Fonction qui renvoie le minimum entre deux nombres flottants
float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
