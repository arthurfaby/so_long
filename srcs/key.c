/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:26:59 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 15:41:26 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "functions.h"
#include "mlx_int.h"


#include "libft.h"

int	check_move(int keycode, t_env *env)
{
	int	x;
	int	y;

	x = env->player->row;
	y = env->player->col;
	if (keycode == 'w')
	{
		if (env->map->board[x - 1][y]->type == WALL)
			return (0);
		return (1);
	}
	if (keycode == 's')
	{
		if (env->map->board[x + 1][y]->type == WALL)
			return (0);
		return (1);
	}
	if (keycode == 'a')
	{
		if (env->map->board[x][y - 1]->type == WALL)
			return (0);
		return (1);
	}
	if (keycode == 'd')
	{
		if (env->map->board[x][y + 1]->type == WALL)
			return (0);
		return (1);
	}
	return (0);
}

void	check_modif(t_env *env)
{
	int	x;
	int	y;

	x = env->player->row;
	y = env->player->col;
	if (env->map->board[x][y]->type == EXIT_ON)
		end_game(env, 1);
	if (env->map->board[x][y]->type == ENEMY)
	{
		env->player->health -= 35;
		env->map->board[x][y]->type = GROUND;
		if (env->player->health <= 0)
			end_game(env, 0);
	}
	if (env->map->board[x][y]->type == COLLECTIBLE)
	{
		env->map->board[x][y]->type = COLLECTED;
		env->player->health += 20;
		if (env->player->health > 100)
			env->player->health = 100;
		env->player->collected++;
	}
	if (env->player->collected == env->map->to_collect)
		open_exit(env);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		end_game(env, -1);
	if (env->in_menu)
	{
		if (keycode == XK_Return && env->selected == 1)
		{
			env->in_menu = 0;
			print_water(env);
			render(env);
		}
	}
	else if (!env->in_menu)
	{
		if (!check_move(keycode, env))
			return (0);
		env->player->moves++;
		if (keycode == 'w')
			env->player->row -= 1;
		else if (keycode == 's')
			env->player->row += 1;
		else if (keycode == 'a')
			env->player->col -= 1;
		else if (keycode == 'd')
			env->player->col += 1;
		check_modif(env);
		render(env);
	}
	return (0);
}
