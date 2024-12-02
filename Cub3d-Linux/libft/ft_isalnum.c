/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:28:55 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 13:34:03 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks for an alphanumeric character. It is equivalent to
 * (isalpha(c) || isdigit(c)).
 *
 * @param c The character to check.
 * @return A non-zero value if c is an alphanumeric character, 0 otherwise.
 */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
