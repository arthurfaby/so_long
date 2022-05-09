/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:07:23 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 16:44:19 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "libft.h"
#include "mlx.h"
#include "functions.h"

void	free_texture(t_env *env)
{
	mlx_destroy_image(env->mlx, env->texture->water);
	mlx_destroy_image(env->mlx, env->texture->ground);
	mlx_destroy_image(env->mlx, env->texture->spawn);
	mlx_destroy_image(env->mlx, env->texture->exit_on);
	mlx_destroy_image(env->mlx, env->texture->exit_off);
	mlx_destroy_image(env->mlx, env->texture->collectible);
	mlx_destroy_image(env->mlx, env->texture->collected);
	mlx_destroy_image(env->mlx, env->texture->wall);
	mlx_destroy_image(env->mlx, env->texture->no_texture);
	mlx_destroy_image(env->mlx, env->texture->player);
	mlx_destroy_image(env->mlx, env->texture->enemy);
	mlx_destroy_image(env->mlx, env->texture->title);
	mlx_destroy_image(env->mlx, env->texture->title_play);
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
		x++;
	}
	free(map->board[x]);
	free(map->board);
	free(map);
}

void	end_game(t_env *env, int code)
{
	if (code == FD_ERR || code == EMPTY_FILE_ERR || code == MALLOC_ERR || code == NOT_RECT_ERR)
		ft_error(code);
	else
	{
		if (code == 1 || code == 0)
		{
			if (code == 1)
				ft_printf("\033[0;32m");
			else if (code == 0)
				ft_printf("\033[0;31m");
			ft_printf("-------------------------\n");
			ft_printf("|  THANKS FOR PLAYING   |\n");
			ft_printf("-------------------------\n");
		}
		else
			ft_error(code);
		mlx_loop_end(env->mlx);
		free_texture(env);
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
