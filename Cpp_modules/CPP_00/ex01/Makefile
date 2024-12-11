# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 16:07:49 by alanty            #+#    #+#              #
#    Updated: 2024/08/07 14:07:28 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
CC = g++
CFLAGS = -Wall -Wextra -std=c++98
NAME = phonebook
SRCS = Contact.cpp main.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

