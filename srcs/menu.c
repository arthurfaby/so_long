/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:57:48 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 11:58:38 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "structures.h"
#include "functions.h"
#include "includes.h"

void	display_menu(t_env *env)
{
	t_image	img;
	int		x;
	int		y;

	if (!env->in_menu)
		return ;
	img.img = mlx_new_image(env->mlx, env->width, env->height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	x = 0;
	while (x < env->height)
	{
		y = 0;
		while (y < env->width)
		{
			img_pixel_put(env, &img, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->texture->title, (env->width - 384) / 2, 50);
	mlx_put_image_to_window(env->mlx, env->win, env->texture->title_play, (env->width - 200) / 2, 200);
	mlx_destroy_image(env->mlx, img.img);
}
