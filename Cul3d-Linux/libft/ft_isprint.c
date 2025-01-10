/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:07:19 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:35:19 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks for any printable character, including space.
 *
 * @param c The character to check.
 * @return A non-zero value if c is a printable character, 0 otherwise.
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
