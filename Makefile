# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/05/12 11:54:49 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/board.c \
		srcs/main.c \
		srcs/map.c \
		srcs/tile.c \
		srcs/texture.c \
		srcs/player.c \
		srcs/key.c \
		srcs/display.c \
		srcs/update.c \
		srcs/interface.c \
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
		srcs/check_rect.c

CC = gcc

INCS = incs/

MLX = libs/minilibx
LIBFT = libs/libft

CFLAGS = -Wall -Wextra -Werror -I$(MLX) -L$(MLX) -lmlx -lXext -lX11 -lm -I$(INCS) -I$(LIBFT) -L$(LIBFT) -lft

RM = rm -f

all: $(NAME)

bonus: all

clean:
	$(RM)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME):
	make re -C $(MLX)
	make re -C $(LIBFT)
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS)

.PHONY: all clean fclean re
