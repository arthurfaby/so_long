/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:45:58 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 11:17:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "functions.h"

void	move_right(t_env *env)
{
	int	x;
	int	y;

	env->player->moves++;
	x = env->player->row;
	y = env->player->col;
	if (env->map->board[x][y + 1]->type == WALL)
		return ;
	env->player->col += 1;
	check_modif(env);
	render(env);
}

void	move_left(t_env *env)
{
	int	x;
	int	y;

	env->player->moves++;
	x = env->player->row;
	y = env->player->col;
	if (env->map->board[x][y - 1]->type == WALL)
		return ;
	env->player->col -= 1;
	check_modif(env);
	render(env);
}

void	move_top(t_env *env)
{
	int	x;
	int	y;

	env->player->moves++;
	x = env->player->row;
	y = env->player->col;
	if (env->map->board[x - 1][y]->type == WALL)
		return ;
	env->player->row -= 1;
	check_modif(env);
	render(env);
}

void	move_bottom(t_env *env)
{
	int	x;
	int	y;

	env->player->moves++;
	x = env->player->row;
	y = env->player->col;
	if (env->map->board[x + 1][y]->type == WALL)
		return ;
	env->player->row += 1;
	check_modif(env);
	render(env);
}

void	check_modif(t_env *env)
{
	int	x;
	int	y;

	x = env->player->row;
	y = env->player->col;
	if (env->map->board[x][y]->type == EXIT_ON)
		end_game(env, 1);
	if (env->map->board[x][y]->type == COLLECTIBLE)
	{
		env->map->board[x][y]->type = COLLECTED;
		env->player->collected++;
	}
	if (env->player->collected == env->map->to_collect)
		open_exit(env);
}
