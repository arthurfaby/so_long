/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:59:14 by afaby             #+#    #+#             */
/*   Updated: 2022/05/11 16:10:14 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "mlx.h"
#include "functions.h"

void	init_env(t_env *env, char *path)
{
	env->map = create_map(path);
	env->mlx = mlx_init();
	env->width = (env->map->n_cols + 8) * 16;
	if (env->width < 800)
		env->width = 800;
	env->height = (env->map->n_rows + 8) * 16;
	if (env->height < 500)
		env->height = 500;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "so_long");
	env->in_menu = 1;
	env->selected = 1;
}
