# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 17:06:18 by alanty            #+#    #+#              #
#    Updated: 2024/04/05 11:57:19 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_calloc.c \
       ft_atoi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_strmapi.c \
       ft_itoa.c \
       ft_split.c \
       ft_substr.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_printf.c \
       ft_putchar_pf.c \
       ft_putstr_pf.c \
       ft_putnbr_pf.c \
       affiche_nombre_non_signe.c \
       aff_hexadecimal.c \
       affiche_pointeur.c \
       conversion_nb_ch.c \
       get_next_line.c \
       get_next_line_bonus.c \
       get_next_line_utils.c \
       get_next_line_utils_bonus.c \
       ft_atoi_base.c \
       ft_split_count.c


OBJS = ${SRCS:.c=.o}

NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
