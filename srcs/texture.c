/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:12:35 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 22:04:46 by afaby            ###   ########.fr       */
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

	t->water = mlx_xpm_file_to_image(env->mlx, "../assets/water.xpm", &width, &height);
	t->ground = mlx_xpm_file_to_image(env->mlx, "../assets/ground.xpm", &width, &height);
	t->spawn = mlx_xpm_file_to_image(env->mlx, "../assets/ground.xpm", &width, &height);
	t->exit = mlx_xpm_file_to_image(env->mlx, "../assets/exit.xpm", &width, &height);
	t->collectable = mlx_xpm_file_to_image(env->mlx,
			"../assets/collectable.xpm", &width, &height);
	t->collected = mlx_xpm_file_to_image(env->mlx,
			"../assets/collected.xpm", &width, &height);
	t->bn = mlx_xpm_file_to_image(env->mlx, "../assets/bn.xpm", &width, &height);
	t->bs = mlx_xpm_file_to_image(env->mlx, "../assets/bs.xpm", &width, &height);
	t->be = mlx_xpm_file_to_image(env->mlx, "../assets/be.xpm", &width, &height);
	t->bw = mlx_xpm_file_to_image(env->mlx, "../assets/bw.xpm", &width, &height);
	t->bne = mlx_xpm_file_to_image(env->mlx, "../assets/bne.xpm", &width, &height);
	t->bnw = mlx_xpm_file_to_image(env->mlx, "../assets/bnw.xpm", &width, &height);
	t->bse = mlx_xpm_file_to_image(env->mlx, "../assets/bse.xpm", &width, &height);
	t->bsw = mlx_xpm_file_to_image(env->mlx, "../assets/bsw.xpm", &width, &height);
}
