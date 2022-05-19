/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:26:55 by afaby             #+#    #+#             */
/*   Updated: 2022/05/08 18:47:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	choose_type(char type)
{
	if (type == '0')
		return (GROUND);
	else if (type == 'P')
		return (SPAWN);
	else if (type == 'C')
		return (COLLECTIBLE);
	else if (type == '1')
		return (WALL);
	else if (type == 'E')
		return (EXIT_OFF);
	else if (type == 'F')
		return (ENEMY);
	return (NO_TEXTURE);
}

t_tile	*create_tile(char type, int row, int col)
{
	t_tile	*new;

	new = malloc(sizeof(t_tile));
	if (!new)
		return (0);
	new->row = row;
	new->col = col;
	new->type = choose_type(type);
	new->width = 16;
	new->height = 16;
	return (new);
}
