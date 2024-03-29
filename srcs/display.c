/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:35:06 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 11:15:34 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "mlx.h"
#include "libft.h"
#include "functions.h"

void	print_water(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->height)
		{
			mlx_put_image_to_window(env->mlx, env->win, env->t->water, x, y);
			y += 16;
		}
		x += 16;
	}
}

void	print_water_banner(t_env *env)
{
	int		y;
	int		x;
	void	*water;

	water = env->t->water;
	x = 0;
	while (x < 2)
	{
		y = 0;
		while (y < env->width)
		{
			mlx_put_image_to_window(env->mlx, env->win, water, y, x * 16);
			y += 16;
		}
		x++;
	}
}

void	print_tile(t_env *env, int x, int y)
{
	int	a;
	int	b;

	a = (x + (env->height / 16 - env->map->n_rows) / 2) * 16;
	b = (y + (env->width / 16 - env->map->n_cols) / 2) * 16;
	if (env->map->board[x][y]->type == GROUND)
		mlx_put_image_to_window(env->mlx, env->win, env->t->ground, b, a);
	else if (env->map->board[x][y]->type == SPAWN)
		mlx_put_image_to_window(env->mlx, env->win, env->t->spawn, b, a);
	else if (env->map->board[x][y]->type == EXIT_ON)
		mlx_put_image_to_window(env->mlx, env->win, env->t->exit_on, b, a);
	else if (env->map->board[x][y]->type == EXIT_OFF)
		mlx_put_image_to_window(env->mlx, env->win, env->t->exit_off, b, a);
	else if (env->map->board[x][y]->type == COLLECTIBLE)
		mlx_put_image_to_window(env->mlx, env->win, env->t->collectible, b, a);
	else if (env->map->board[x][y]->type == COLLECTED)
		mlx_put_image_to_window(env->mlx, env->win, env->t->collected, b, a);
	else if (env->map->board[x][y]->type == WALL)
		mlx_put_image_to_window(env->mlx, env->win, env->t->wall, b, a);
}

void	print_player(t_env *env)
{
	int	x;
	int	y;
	int	row;
	int	col;

	row = env->player->row;
	col = env->player->col;
	x = (row + (env->height / 16 - env->map->n_rows) / 2) * 16;
	y = (col + (env->width / 16 - env->map->n_cols) / 2) * 16;
	mlx_put_image_to_window(env->mlx, env->win, env->t->player, y, x);
}

void	print_moves(t_env *env)
{
	ft_printf("Number of moves : %d\n", env->player->moves);
}
