/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:12:35 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 18:15:10 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "structures.h"

void	charge_texture(t_env *env, t_texture *t)
{
	t->water = mlx_xpm_file_to_image(env->mlx, "../assets/water.xpm", 16, 16);
	t->ground = mlx_xpm_file_to_image(env->mlx, "../assets/ground.xpm", 16, 16);
	t->spawn = mlx_xpm_file_to_image(env->mlx, "../assets/ground.xpm", 16, 16);
	t->exit = mlx_xmp_file_to_image(env->mlx, "../assets/exit.xpm", 16, 16);
	t->collectable = mlx_xmp_file_to_image(env->mlx,
			"../assets/collectable.xpm", 16, 16);
	t->collected = mlx_xmp_file_to_image(env->mlx,
			"../assets/collected.xpm", 16, 16);
	t->bn = mlx_xmp_file_to_image(env->mlx, "../assets/bn.xpm", 16, 16);
	t->bs = mlx_xmp_file_to_image(env->mlx, "../assets/bs.xpm", 16, 16);
	t->be = mlx_xmp_file_to_image(env->mlx, "../assets/be.xpm", 16, 16);
	t->bw = mlx_xmp_file_to_image(env->mlx, "../assets/bw.xpm", 16, 16);
	t->bne = mlx_xmp_file_to_image(env->mlx, "../assets/bne.xpm", 16, 16);
	t->bnw = mlx_xmp_file_to_image(env->mlx, "../assets/bnw.xpm", 16, 16);
	t->bse = mlx_xmp_file_to_image(env->mlx, "../assets/bse.xpm", 16, 16);
	t->bsw = mlx_xmp_file_to_image(env->mlx, "../assets/bsw.xpm", 16, 16);
}
