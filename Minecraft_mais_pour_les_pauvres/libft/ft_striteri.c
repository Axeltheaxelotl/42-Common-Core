/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:07:46 by smasse            #+#    #+#             */
/*   Updated: 2024/11/18 14:14:26 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies the function f to each character of the string passed as argument,
 * and passing its index as first argument. Each character is passed by address
 * to f to be modified if necessary.
 *
 * @param s The string to iterate.
 * @param f The function to apply to each character.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(i++, s++);
	}
}
