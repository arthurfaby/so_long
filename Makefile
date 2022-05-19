# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/05/19 11:16:35 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS =	bonus/board_bonus.c \
		bonus/main_bonus.c \
		bonus/map_bonus.c \
		bonus/tile_bonus.c \
		bonus/texture_bonus.c \
		bonus/player_bonus.c \
		bonus/key_bonus.c \
		bonus/display_bonus.c \
		bonus/update_bonus.c \
		bonus/interface_bonus.c \
		bonus/menu_bonus.c \
		bonus/image_bonus.c \
		bonus/end_bonus.c \
		bonus/error_bonus.c \
		bonus/check_wall_bonus.c \
		bonus/render_bonus.c \
		bonus/moves_bonus.c \
		bonus/env_bonus.c \
		bonus/print_bonus.c \
		bonus/check_min_bonus.c \
		bonus/check_rect_bonus.c \
		bonus/move_enemy_bonus.c

SRCS =	srcs/board.c \
		srcs/main.c \
		srcs/map.c \
		srcs/tile.c \
		srcs/texture.c \
		srcs/player.c \
		srcs/key.c \
		srcs/display.c \
		srcs/update.c \
		srcs/menu.c \
		srcs/image.c \
		srcs/end.c \
		srcs/error.c \
		srcs/check_wall.c \
		srcs/render.c \
		srcs/moves.c \
		srcs/env.c \
		srcs/print.c \
		srcs/check_min.c \
		srcs/check_rect.c \

CC = gcc

MLX = libs/minilibx
LIBFT = libs/libft

CFLAGS = -Wall -Wextra -Werror -L$(MLX) -lmlx -lXext -lX11 -lm -L$(LIBFT) -lft

INCS = -Iincs/ -I$(LIBFT) -I$(MLX)
INCS_BONUS = -Iincs_bonus/ -I$(LIBFT) -I$(MLX)

RM = rm -f

all: $(NAME)

bonus:
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) -g $(BONUS) $(CFLAGS) $(INCS_BONUS) -o $(NAME)

clean:
	make clean -C $(MLX)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

$(NAME):
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS) $(INCS)

.PHONY: all clean fclean bonus re
