/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:03:28 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 10:04:04 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	img_pixel_put(t_env *env, t_image *img, int y, int x, int color)
{
	char	*pixel;
	int		i;

	if (y >= env->height || y < 0)
		return ;
	if (x >= env->width || x < 0)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len) + x * (img->bpp / 8);
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}	
}
