/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:12:35 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 16:09:07 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "structures.h"
#include "mlx.h"
#include "includes.h"

void	charge_texture_menu(t_env *env, t_texture *t)
{
	int	trash;

	t->title = mlx_xpm_file_to_image(env->mlx,
			"assets/title.xpm", &trash, &trash);
	t->title_play = mlx_xpm_file_to_image(env->mlx,
			"assets/title_play.xpm", &trash, &trash);
}

void	charge_texture_entity(t_env *env, t_texture *t)
{
	int	trash;

	t->player = mlx_xpm_file_to_image(env->mlx,
			"assets/player.xpm", &trash, &trash);
	t->player2 = mlx_xpm_file_to_image(env->mlx,
			"assets/player2.xpm", &trash, &trash);
	t->player3 = mlx_xpm_file_to_image(env->mlx,
			"assets/player3.xpm", &trash, &trash);
	t->enemy = mlx_xpm_file_to_image(env->mlx,
			"assets/enemy.xpm", &trash, &trash);
}

void	charge_texture_struct(t_env *env, t_texture *t)
{
	int	trash;

	t->ground = mlx_xpm_file_to_image(env->mlx,
			"assets/ground.xpm", &trash, &trash);
	t->wall = mlx_xpm_file_to_image(env->mlx,
			"assets/wall.xpm", &trash, &trash);
}

void	charge_texture(t_env *env, t_texture *t)
{
	int	trash;

	t->water = mlx_xpm_file_to_image(env->mlx,
			"assets/water.xpm", &trash, &trash);
	t->spawn = mlx_xpm_file_to_image(env->mlx,
			"assets/spawn.xpm", &trash, &trash);
	t->exit_on = mlx_xpm_file_to_image(env->mlx,
			"assets/exit_on.xpm", &trash, &trash);
	t->exit_off = mlx_xpm_file_to_image(env->mlx,
			"assets/exit_off.xpm", &trash, &trash);
	t->collectible = mlx_xpm_file_to_image(env->mlx,
			"assets/collectible.xpm", &trash, &trash);
	t->collected = mlx_xpm_file_to_image(env->mlx,
			"assets/collected.xpm", &trash, &trash);
	t->no_texture = mlx_xpm_file_to_image(env->mlx,
			"assets/no_texture.xpm", &trash, &trash);
	charge_texture_struct(env, t);
	charge_texture_entity(env, t);
	charge_texture_menu(env, t);
}
