/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:56:10 by smasse            #+#    #+#             */
/*   Updated: 2024/11/21 19:24:51 by smasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <immintrin.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# if defined(__x86_64__) || defined(_M_X64)
typedef uint64_t	word_t;
#  define WORD_SIZE 8
# else
typedef uint32_t	word_t;
#  define WORD_SIZE 4
# endif

void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t length);
char				*ft_strchr(const char *s, int ch);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strchr(const char *s, int ch);
char				*ft_strrchr(const char *s, int ch);
int					ft_atoi(const char *nptr);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_appendchar(char *start, char c);
char				*ft_strcat(char *dest, char *src);
void				ft_putendl_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					printfft_putnbr(int nb);
long unsigned int	printfft_strlen(const char *str);
int					printfft_putchar(char c);
int					printfft_putstr(char *str);
int					printfft_puthexa(unsigned int nb, int is_upper);
int					printfft_putunsigned(unsigned long n);
int					printfft_putaddress(void *format);
char				*printfft_strchr(const char *s, int c);
int					ft_printf(const char *str, ...);
int					printfrec_print(unsigned long n, const char *base);
int					ft_isdigits(char *str);
char				*get_next_line(int fd);
int					gnl(int fd, char **line);
int					ft_open(const char *path, int flags);
int					ft_close(int fd, char **l, int return_value);
int					ft_isnum(int c);
#endif