/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:25:36 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 15:42:03 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "structures.h"
#include <time.h>

void	move_enemy_top(t_env *env, int x, int y)
{
	if (env->map->board[x][y]->type == ENEMY)
	{
		if (env->map->board[x - 1][y]->type == GROUND)
		{
			env->map->board[x - 1][y]->type = ENEMY;
			env->map->board[x][y]->type = GROUND;
		}
	}
}

void	move_enemy_bot(t_env *env, int x, int y)
{
	if (env->map->board[x][y]->type == ENEMY)
	{
		if (env->map->board[x + 1][y]->type == GROUND)
		{
			env->map->board[x + 1][y]->type = ENEMY;
			env->map->board[x][y]->type = GROUND;
		}
	}
}

void	move_enemy_right(t_env *env, int x, int y)
{
	if (env->map->board[x][y]->type == ENEMY)
	{
		if (env->map->board[x][y + 1]->type == GROUND)
		{
			env->map->board[x][y + 1]->type = ENEMY;
			env->map->board[x][y]->type = GROUND;
		}
	}
}

void	move_enemy_left(t_env *env, int x, int y)
{
	if (env->map->board[x][y]->type == ENEMY)
	{
		if (env->map->board[x][y - 1]->type == GROUND)
		{
			env->map->board[x][y - 1]->type = ENEMY;
			env->map->board[x][y]->type = GROUND;
		}
	}
}

void	move_enemies(t_env *env)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	srand(time(NULL));
	while (env->map->board[x])
	{
		y = 0;
		while (env->map->board[x][y])
		{
			n = rand() % 4;
			if (n == 0)
				move_enemy_top(env, x, y);
			else if (n == 1)
				move_enemy_bot(env, x, y);
			else if (n == 2)
				move_enemy_right(env, x, y);
			else
				move_enemy_left(env, x, y);
			y++;
		}
		x++;
	}
}
