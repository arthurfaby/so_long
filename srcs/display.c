/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:35:06 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 11:48:30 by afaby            ###   ########.fr       */
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
			mlx_put_image_to_window(env->mlx, env->win, env->texture->water, x, y);
			y += 16;
		}
		x += 16;
	}
}

void	print_water_banner(t_env *env)
{
	int	y;
	int	x;

	x = 0;
	while (x < 2)
	{
		y = 0;
		while (y < env->width)
		{
			mlx_put_image_to_window(env->mlx, env->win, env->texture->water, y, x * 16);
			y += 16;
		}
		x++;
	}
}

void	print_tile(t_env *env, int x, int y)
{
	int	xof;
	int	yof;

	xof = (env->height / 16 - env->map->n_rows) / 2;
	yof = (env->width / 16 - env->map->n_cols) / 2;
	if (env->map->board[x][y]->type == GROUND)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->ground, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == SPAWN)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->spawn, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == EXIT_ON)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->exit_on, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == EXIT_OFF)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->exit_off, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == COLLECTIBLE)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->collectible, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == COLLECTED)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->collected, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == WALL)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->wall, (y + yof) * 16, (x + xof) * 16);
	else if (env->map->board[x][y]->type == ENEMY)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->enemy, (y + yof) * 16, (x + xof) * 16);
	else
		mlx_put_image_to_window(env->mlx, env->win, env->texture->no_texture, (y + yof) * 16, (x + xof) * 16);
}

void	print_player(t_env *env)
{
	int	x;
	int	y;

	x = env->player->row + (env->height / 16 - env->map->n_rows) / 2;
	y = env->player->col + (env->width / 16 - env->map->n_cols) / 2;
	mlx_put_image_to_window(env->mlx, env->win, env->texture->player, y * 16, x * 16);
}

void	print_moves(t_env *env)
{
	char	*str;
	char	*str2;

	str2 = ft_itoa(env->player->moves);
	str = ft_strjoin("Number of moves : ", str2);
	free(str2);
	str2 = NULL;
	mlx_string_put(env->mlx, env->win, 10, 20, 0xFFFFFF, str);
	free(str);
	str = NULL;
}

int	render(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	if (env->in_menu)
	{
		display_menu(env);
		return (0);
	}
	print_water_banner(env);
	print_moves(env);
	if (env->win)
	{
		while (env->map->board[x])
		{
			y = 0;
			while (env->map->board[x][y])
			{
				print_tile(env, x, y);
				y++;
			}
			x++;
		}
	}
	print_player(env);
	display_health(env);
	display_progression(env);
	return (0);
}
