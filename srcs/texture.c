/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:12:35 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 11:13:35 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "structures.h"
#include "mlx.h"
#include "includes.h"

void	charge_texture(t_env *env, t_texture *t)
{
	int	width;
	int	height;

	t->water = mlx_xpm_file_to_image(env->mlx,
			"assets/water.xpm", &width, &height);
	t->ground = mlx_xpm_file_to_image(env->mlx,
			"assets/ground.xpm", &width, &height);
	t->spawn = mlx_xpm_file_to_image(env->mlx,
			"assets/spawn.xpm", &width, &height);
	t->exit_on = mlx_xpm_file_to_image(env->mlx,
			"assets/exit_on.xpm", &width, &height);
	t->exit_off = mlx_xpm_file_to_image(env->mlx,
			"assets/exit_off.xpm", &width, &height);
	t->collectible = mlx_xpm_file_to_image(env->mlx,
			"assets/collectible.xpm", &width, &height);
	t->collected = mlx_xpm_file_to_image(env->mlx,
			"assets/collected.xpm", &width, &height);
	t->no_texture = mlx_xpm_file_to_image(env->mlx,
			"assets/no_texture.xpm", &width, &height);
	t->wall = mlx_xpm_file_to_image(env->mlx,
			"assets/wall.xpm", &width, &height);
	t->player = mlx_xpm_file_to_image(env->mlx,
			"assets/player.xpm", &width, &height);
	t->enemy = mlx_xpm_file_to_image(env->mlx,
			"assets/enemy.xpm", &width, &height);
	t->title = mlx_xpm_file_to_image(env->mlx,
			"assets/title.xpm", &width, &height);
	t->title_play = mlx_xpm_file_to_image(env->mlx,
			"assets/title_play.xpm", &width, &height);
}
