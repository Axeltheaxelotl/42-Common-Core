NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c simulation.c philosopher.c monitor.c cleanup.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lpthread

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
