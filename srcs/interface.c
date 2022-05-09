/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:06:42 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 11:58:45 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "mlx.h"
#include "libft.h"
#include "functions.h"

void	display_progression(t_env *env)
{
	char	*str;
	char	*str2;
	char	*str3;
	int		collected;
	int		to_collect;

	collected = env->player->collected;
	to_collect = env->map->to_collect;
	str3 = ft_itoa(collected);
	str = ft_strjoin(str3, "/");
	free(str3);
	str3 = NULL;
	str3 = ft_itoa(to_collect);
	str2 = ft_strjoin(str, str3);
	free(str3);
	str3 = NULL;
	free(str);
	str = NULL;
	str = ft_strjoin(str2, " cakes");
	free(str2);
	str2 = NULL;
	mlx_string_put(env->mlx, env->win, env->width - 70, 20, 0x00FF00, str);
	free(str);
	str = NULL;
}

void	display_health(t_env *env)
{
	int		x;
	int		y;
	t_image	img;
	double	width_health;

	width_health = ((double)env->width / 3 - 3) * (double)env->player->health / 100;
	x = 0;
	img.img = mlx_new_image(env->mlx, env->width / 3, 30);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	while (x < 30)
	{
		y = 0;
		while (y < env->width / 3)
		{
			if (x >= 3 && x <= 27 && y >= 3 && y <= (int)width_health)
				img_pixel_put(env, &img, x, y, 0xFF0000);
			else
				img_pixel_put(env, &img, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 10, env->height - 40);
	mlx_destroy_image(env->mlx, img.img);
}
