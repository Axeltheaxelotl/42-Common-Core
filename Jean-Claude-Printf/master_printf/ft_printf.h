/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:00:33 by smasse            #+#    #+#             */
/*   Updated: 2024/09/15 21:02:15 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_items
{
	va_list	args;
	int		dash;
	int		zero;
	int		point;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		length;
	int		precision;
	int		baselen;
	char	specifier;
	char	*base;
	int		base_n;
}			t_struct;

int			ft_printf(const char *format, ...);
void		init_struct(t_struct *item);
void		print_u(t_struct *item);
char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
int			ft_width(t_struct *item, const char *s, int pos);
int			ft_decimal(t_struct *item, const char *s, int pos);
void		pad_zeros(t_struct *item, int len);
void		ft_align(t_struct *item, int len);
void		ft_left_align(t_struct *item, int len);
int			ft_strlen(char *str);
void		print_char(t_struct *item);
void		print_str(t_struct *item);
void		ft_putchar(char c);
int			ft_len_base(long int n, int base);
void		ft_putnum_base(long int n, char *base);
void		print_ptr(t_struct *item);
void		print_nbr(t_struct *item);
void		print_hex(t_struct *item);
void		ft_print_hex_u(t_struct *item);
void		print_per(t_struct *item);
int			ft_check(const char *format, int pos);
int			ft_err(t_struct *item, const char *format, int pos);

#endif
