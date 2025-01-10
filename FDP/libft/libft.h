/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:02:25 by alanty            #+#    #+#             */
/*   Updated: 2024/04/21 15:28:43 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

typedef struct s_liste
{
	char			lettre;
	struct s_liste	*suivant;
}	t_liste;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *str, char *to_find);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putnbr_pf(int num, size_t *compteur);
void			ft_putchar_pf(char c, size_t *compteur);
char			*conversion_nb_ch(unsigned long long n, char *base);
void			aff_hexadecimal(unsigned int nb, size_t *cmp, char *base);
void			affiche_pointeur(void *ptr, size_t *compteur);
void			affiche_nombre_non_signe(unsigned int nombre, size_t *compteur);
void			ft_putstr_pf(char *str, size_t *compteur);
int				ft_printf(char const *str, ...);
void			affiche_nombre_non_signe(unsigned int nombre, size_t *compteur);
t_liste			*ft_lstnew(char lettre);
char			*get_next_line(int fd);
char			*liste_vers_chaine(t_liste **lst);
void			remplir_liste(t_liste **lst, t_liste *dernier, int fd);
int				obtenir_nl(t_liste *lst);
int				obtenir_longeur(t_liste *lst, int i);
t_liste			*dernier(t_liste *lst);
char			*obtenir_ligne_suivante(int fd);
int				ft_atoi_base(char *str, char *base);
size_t			ft_split_count(const char *s, char c);

#endif
