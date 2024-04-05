/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:55:36 by alanty            #+#    #+#             */
/*   Updated: 2024/03/04 10:19:41 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	ft_printf("Chaîne de caractères : %s\n", "Bonjour");
	ft_printf("Entier signé : %d\n", 123);
	ft_printf("Entier non signé : %u\n", 456);
	ft_printf("Caractère : %c\n", 'A');
	ft_printf("Pointeur : %p\n", (void *)0x12345678);
	ft_printf("Nombre hexadecimal en minuscules : %x\n", 255);
	ft_printf("Nombre hexadecimal en majuscules : %X\n", 255);
	ft_printf("Pourcentage : %%\n");
	
	return 0;
}
