# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 13:29:46 by alanty            #+#    #+#              #
#    Updated: 2024/05/11 12:36:30 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard src/*.c utils/*.c)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
