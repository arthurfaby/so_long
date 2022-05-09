/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:41:43 by afaby             #+#    #+#             */
/*   Updated: 2022/05/08 14:44:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	open_exit(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (env->map->board[x])
	{
		y = 0;
		while (env->map->board[x][y])
		{
			if (env->map->board[x][y]->type == EXIT_OFF)
				env->map->board[x][y]->type = EXIT_ON;
			y++;
		}
		x++;
	}
}
