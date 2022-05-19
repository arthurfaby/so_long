/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:25:26 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 14:48:52 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				print_tile(env, x, y++);
			x++;
		}
	}
	print_player(env);
	display_health(env);
	display_progression(env);
	return (0);
}
