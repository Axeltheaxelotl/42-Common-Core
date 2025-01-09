# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smasse <smasse@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:20:44 by smasse            #+#    #+#              #
#    Updated: 2024/12/03 18:18:59 by smasse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  Cub3D
CC = clang
CFLAGS = -Wall -Wextra -Ofast -march=native -ffast-math -flto
INCLUDES = -I./libft -I./minilibx-linux
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a
DEBUG_FLAGS = -00 -g3 -flto
OBJ_DIR = ./objs

SRCS =	errors.c\
		get_next_line.c\
		get_next_line_utils.c\
		init.c\
		keys_draw.c\
		minimap.c\
		parsing_color_resolution_texture.c\
		parsing_map.c\
		parsing_utils.c\
		parsing.c\
		raycasting_init.c\
		raycasting_move.c\
		raycasting_utils.c\
		raycasting.c\
		save.c\
		sprites.c\
		gif.c

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Colors
ERASE	:=	\033[2K\r
BLUE    :=  \033[34m
YELLOW  :=  \033[33m
GREEN   :=  \033[32m
END     :=  \033[0m

LFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lX11 -lXext -lXrender -lm -flto

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@printf "$(BLUE)> Compiling $(NAME)... <$(END)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) -o $(NAME)
	@printf "$(ERASE)$(BLUE)> $@ made <$(END)\n"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(ERASE)$(BLUE)> Compilation : <$(END) $<"

debug: CFLAGS = $(DEBUG_FLAGS)
debug: 
	@printf "$(BLUE)> Debug mode <$(END)\n"
	@$(MAKE) -C $(LIBFT_DIR) debug --silent
	@$(MAKE) -C $(MLX_DIR) debug --silent
	@$(MAKE) all --silent
$(LIBFT):
	@if ! make -C $(LIBFT_DIR) --silent ; then echo "$(BLUE)> Error compiling libft <$(END)\n"; exit 1; fi
$(MLX):
	@if ! make -C $(MLX_DIR) --silent ; then echo "$(BLUE)> Error compiling minilibx-linux <$(END)\n"; exit 1; fi

clean:
	@printf "$(BLUE)> Removing objects... <$(END)"
	@for obj in $(OBJS); do \
		rm -f $$obj && printf "$(ERASE)$(BLUE)> Removed $$obj <$(END)"; \
		sleep 0.01; \
	done
	@printf "$(ERASE)$(BLUE)> Cub3D objects removed <$(END)\n"
	@printf "$(BLUE)> Removing libft objects <$(END)"
	@make -C $(LIBFT_DIR) clean --silent
	@printf "$(ERASE)$(BLUE)> libft objects removed <$(END)\n"
	@printf "$(BLUE)> Removing minilibx-linux objects <$(END)"
	@make -C $(MLX_DIR) clean --silent
	@printf "$(ERASE)$(BLUE)> minilibx-linux objects removed <$(END)\n"

fclean: clean
	@printf "$(BLUE)> Removing $(NAME)... <$(END)"
	@rm -f $(NAME)
	@printf "$(ERASE)$(BLUE)> $(NAME) removed <$(END)\n"
	@printf "$(BLUE)> Removing libft... <$(END)"
	@rm -f $(LIBFT)
	@printf "$(ERASE)$(BLUE)> libft removed <$(END)\n"

norm:
	@echo "$(BLUE)> Running normino -x minilibx-linux... <$(END)"
	@normino -x ./minilibx-linux ./so_long

re: 
	@$(MAKE) fclean --silent
	@printf "$(BLUE)―――――――――――――――――――――――――――――$(END)\n"
	@$(MAKE) all --silent

.PHONY: all clean fclean re debug
