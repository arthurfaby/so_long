/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:43:05 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 10:25:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player(t_env *env, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	player->moves = 0;
	player->col = 1;
	player->row = 1;
	player->health = 100;
	player->collected = 0;
	while (env->map->board[x])
	{
		y = 0;
		while (env->map->board[x][y])
		{
			if (env->map->board[x][y]->type == SPAWN)
			{
				player->col = y;
				player->row = x;
				return ;
			}
			y++;
		}
		x++;
	}
}
