# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 12:28:50 by smasse            #+#    #+#              #
#    Updated: 2024/12/03 18:20:46 by smasse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_atol.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_atoi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_open.c \
		ft_memmove.c \
		ft_appendchar.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strcat.c\
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_isdigits.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_striteri.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_split.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstlast.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c\
		ft_lstmap.c\
		ft_other.c\
		ft_printf.c\
		ft_put.c\
		ft_strcpy.c
		
OBJS = $(SRCS:%.c=%.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -ffast-math -flto
AR = llvm-ar-12 rcs
RANLIB = llvm-ranlib-12

ERASE   :=  \033[2K\r
BLUE    :=  \033[34m
YELLOW  :=  \033[33m
GREEN   :=  \033[32m
END     :=  \033[0m

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@
			printf "$(ERASE)$(BLUE)> Compilation : <$(END) $<"

$(NAME):	$(OBJS)
			@$(AR) $@ $^
			@$(RANLIB) $@
			@printf "$(ERASE)$(BLUE)> $@ made <$(END)\n"

all:		$(NAME)

bonus:		$(NAME)

clean:
			@printf "$(BLUE)> Removing objects... <$(END)"
			@for obj in $(OBJS); do \
				rm -f $$obj && printf "$(ERASE)$(BLUE)> Removed $$obj <$(END)"; \
				sleep 0.01; \
			done

fclean:		clean
			@$(RM) $(NAME)
			@-$(RM) libft.so

re:			fclean all

debug:		CFLAGS = -g3 -fsanitize=address -O0
debug:		re

.PHONY:		all clean fclean re bonus debug
