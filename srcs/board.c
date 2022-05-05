/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:52:17 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 19:04:23 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "includes.h"
#include "defines.h"
#include "libft.h"
#include "functions.h"

t_tile	***malloc_board(int	n_rows, int n_cols)
{
	t_tile	***board;
	int		i;

	i = 0;
	board = malloc(sizeof(t_tile **) * n_rows);
	while (i < n_cols)
	{
		board[i] = malloc(sizeof(t_tile *));
		i++;
	}
	return (board);
}

int	create_board(t_map *map, char *path)
{
	int		fd;
	char	*line;
	int		row;
	int		col;
	int		i;

	row = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, BUFFER_SIZE);
	while (line)
	{
		col = 0;
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			map->board[row][col] = create_tile(map, line[i], row, col);
			col++;
			i++;
		}
		map->board[row][col] = 0;
		//free(line);
		line = get_next_line(fd, BUFFER_SIZE);
		row++;
	}
	map->board[row] = 0;
	return (0);
}
