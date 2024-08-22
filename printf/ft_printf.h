/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:18:53 by alanty            #+#    #+#             */
/*   Updated: 2024/02/28 15:36:20 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

void	ft_putnbr_pf(int num, size_t *compteur);
void	ft_putchar_pf(char c, size_t *compteur);
char	*conversion_nombre_vers_chaine(unsigned long long n, char *base);
void	aff_hexadecimal(unsigned int nombre, size_t *compteur, char *base);
void	affiche_pointeur(void *ptr, size_t *compteur);
void	affiche_nombre_non_signe(unsigned int nombre, size_t *compteur);
void	ft_putstr_pf(char *str, size_t *compteur);
int		ft_printf(char const *str, ...);
void	affiche_nombre_non_signe(unsigned int nombre, size_t *compteur);

#endif
