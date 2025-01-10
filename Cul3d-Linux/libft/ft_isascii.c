/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:37:17 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:34:24 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks for an ASCII character, which is any character between 0 and 127.
 *
 * @param c The character to check.
 * @return A non-zero value if c is an ASCII character, 0 otherwise.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
