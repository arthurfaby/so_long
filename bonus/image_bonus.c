/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:03:28 by afaby             #+#    #+#             */
/*   Updated: 2022/05/11 15:06:13 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_pixel_put(t_image *img, int y, int x, int color)
{
	char	*pixel;
	int		i;

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
