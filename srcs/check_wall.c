/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:52:45 by afaby             #+#    #+#             */
/*   Updated: 2022/05/10 14:56:52 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "functions.h"

void	check_top(t_map *map)
{
	int	i;

	i = 0;
	while (map->board[0][i])
	{
		if (map->board[0][i]->type != WALL)
		{
			free_map(map);
			end_game(0, WALL_ERR);
		}
		i++;
	}
}

void	check_bot(t_map *map)
{
	int	i;

	i = 0;
	while (map->board[map->n_rows - 1][i])
	{
		if (map->board[map->n_rows - 1][i]->type != WALL)
		{
			free_map(map);
			end_game(0, WALL_ERR);
		}
		i++;
	}
}

void	check_left(t_map *map)
{
	int	i;

	i = 0;
	while (map->board[i])
	{
		if (map->board[i][0]->type != WALL)
		{
			free_map(map);
			end_game(0, WALL_ERR);
		}
		i++;
	}
}

void	check_right(t_map *map)
{
	int	i;

	i = 0;
	while (map->board[i])
	{
		if (map->board[i][map->n_cols - 1]->type != WALL)
		{
			free_map(map);
			end_game(0, WALL_ERR);
		}
		i++;
	}
}

void	check_wall(t_map *map)
{
	check_top(map);
	check_bot(map);
	check_left(map);
	check_right(map);
}
