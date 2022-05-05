/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:26:55 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 18:59:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "defines.h"
#include "includes.h"

int	choose_type(t_map *map, char type, int y, int x)
{
	if (type == '0')
		return (GROUND);
	else if (type == 'P')
		return (SPAWN);
	else if (type == 'C')
		return (COLLECTABLE);
	else if (type == '1' && x == 0 && y == 0)
		return (BORDER_NW);
	else if (type == '1' && x == 0 && y == map->n_cols - 1)
		return (BORDER_NE);
	else if (type == '1' && x == map->n_rows - 1 && y == 0)
		return (BORDER_SW);
	else if (type == '1' && x == map->n_rows - 1 && y == map->n_cols - 1)
		return (BORDER_SE);
	else if (type == '1' && x == 0)
		return (BORDER_N);
	else if (type == '1' && x == map->n_rows - 1)
		return (BORDER_S);
	else if (type == '1' && y == 0)
		return (BORDER_W);
	else if (type == '1' && y == map->n_cols - 1)
		return (BORDER_E);
	return (WATER);
}

t_tile	*create_tile(t_map *map, char type, int row, int col)
{
	t_tile	*new;

	new = malloc(sizeof(t_tile));
	if (!new)
		return (0);
	new->row = row;
	new->col = col;
	new->type = choose_type(map, type, col, row);
	new->width = 16;
	new->height = 16;
	return (new);
}
