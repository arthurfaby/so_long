/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:07:23 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 17:22:41 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "libft.h"
#include "mlx.h"
#include "functions.h"

void	free_t(t_env *env)
{
	mlx_destroy_image(env->mlx, env->t->water);
	mlx_destroy_image(env->mlx, env->t->ground);
	mlx_destroy_image(env->mlx, env->t->spawn);
	mlx_destroy_image(env->mlx, env->t->exit_on);
	mlx_destroy_image(env->mlx, env->t->exit_off);
	mlx_destroy_image(env->mlx, env->t->collectible);
	mlx_destroy_image(env->mlx, env->t->collected);
	mlx_destroy_image(env->mlx, env->t->wall);
	mlx_destroy_image(env->mlx, env->t->no_texture);
	mlx_destroy_image(env->mlx, env->t->player);
	mlx_destroy_image(env->mlx, env->t->player2);
	mlx_destroy_image(env->mlx, env->t->player3);
	mlx_destroy_image(env->mlx, env->t->enemy);
	mlx_destroy_image(env->mlx, env->t->title);
	mlx_destroy_image(env->mlx, env->t->title_play);
}

void	free_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			free(map->board[x][y]);
			y++;
		}
		free(map->board[x][y]);
		free(map->board[x]);
		x++;
	}
	free(map->board[x]);
	free(map->board);
	free(map);
}

void	end_game(t_env *env, int code)
{
	int	moves;

	if (!env)
		ft_error(code);
	else
	{
		if (code == 1 || code == 0)
		{
			moves = env->player->moves;
			if (code == 1)
				ft_printf("\033[0;32mWon with %d moves :)\n", moves);
			else if (code == 0)
				ft_printf("\033[0;31mLose :(\n");
		}
		else
			ft_error(code);
		mlx_loop_end(env->mlx);
		free_t(env);
		free_map(env->map);
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	exit(1);
}

int	quit(t_env *env)
{
	end_game(env, -1);
	return (0);
}
