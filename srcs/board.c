/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:52:17 by afaby             #+#    #+#             */
/*   Updated: 2022/05/10 18:11:25 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "includes.h"
#include "defines.h"
#include "libft.h"
#include "functions.h"

t_tile	***malloc_board(int n_rows, int n_cols)
{
	t_tile	***board;
	int		i;

	i = 0;
	board = malloc(sizeof(t_tile **) * (n_rows + 1));
	while (i < n_rows)
	{
		board[i] = malloc(sizeof(t_tile *) * (n_cols + 1));
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

	row = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, BUFFER_SIZE);
	while (line)
	{
		col = 0;
		while (line[col] && line[col] != '\n')
		{
			map->board[row][col] = create_tile(line[col], row, col);
			col++;
		}
		map->board[row][col] = 0;
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
		row++;
	}
	map->board[row] = 0;
	return (0);
}
