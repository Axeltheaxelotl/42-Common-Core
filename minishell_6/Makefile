# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 18:15:29 by alanty            #+#    #+#              #
#    Updated: 2024/07/05 18:22:21 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = minishell
CC = gcc
CFLAGS = -Wall -Wextra -g
SRCDIR = src
INCDIR = include
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/lib/libft.a

# List of source files
SRC = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/builtins/*.c $(SRCDIR)/gros/*.c $(SRCDIR)/utils/*.c $(SRCDIR)/utils/executils/*.c $(SRCDIR)/utils/exputils/*.c $(SRCDIR)/utils/getset/*.c $(SRCDIR)/utils/lexutils/*.c $(SRCDIR)/utils/parserutils/*.c)
OBJ = $(SRC:.c=.o)

# Compilation
$(TARGET): $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFTDIR)/lib -lft -lreadline   # Ajout de -lreadline ici

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFTDIR) fclean

re: fclean $(TARGET)

.PHONY: all clean fclean re
