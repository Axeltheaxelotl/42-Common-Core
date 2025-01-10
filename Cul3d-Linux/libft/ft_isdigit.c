/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:21:16 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:35:13 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks for a digit (0 through 9).
 *
 * @param c The character to check.
 * @return A non-zero value if c is a digit, 0 otherwise.
 */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
