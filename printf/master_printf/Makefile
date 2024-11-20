# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 12:00:27 by smasse            #+#    #+#              #
#    Updated: 2024/09/11 19:19:40 by smasse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_printf.c \
      ft_print_chars.c \
      ft_print_ptr.c \
      ft_print_nbrs.c \
      ft_printf_utils.c \
      ft_width.c \
      ft_print_hex.c \
      ft_check.c

# Object files
OBJS = $(SRC:.c=.o)

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -rf $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus