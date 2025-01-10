/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:38:08 by smasse            #+#    #+#             */
/*   Updated: 2024/11/25 10:20:32 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * Checks for a numeric character.
 *
 * @param c The character to check.
 * @return A non-zero value if c is a numeric character, 0 otherwise.
 */

bool	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
