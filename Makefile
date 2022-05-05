# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/05/05 15:13:51 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/board.c \
		srcs/main.c \
		srcs/map.c \
		srcs/tile.c

CC = gcc

INCS = incs/

MLX = libs/minilibx
LIBFT = libs/libft

CFLAGS = -Wall -Wextra -Werror -I$(MLX) -L$(MLX) -lmlx -lXext -lX11 -lm -I$(INCS) -I$(LIBFT)

#-L$(LIBFT) -lft


all: $(NAME)

$(NAME):
	@echo "\033[0;32mChecking libft.a"
	@make -sC $(LIBFT)
	@echo "\033[0;32mChecking mlx.a"
	@make -sC $(MLX)
	@$(CC) -g $(SRCS) libs/libft/*/*.o -o $(NAME) $(CFLAGS)

clean:
	@rm -f $(NAME)

re: clean all
