/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:34:03 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 15:16:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "defines.h"
#include "includes.h"
#include "libft.h"
#include "functions.h"

int	count_cols(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
		return (-2);
	close(fd);
	return (ft_strlen(line) - 1);
}

int	count_rows(char *path)
{
	int		fd;
	int		n_rows;
	char	*line;

	fd = open(path, O_RDONLY);
	n_rows = 0;
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
		return (-1);
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd, BUFFER_SIZE);
		n_rows++;
	}
	close(fd);
	return (n_rows);
}

t_map	*create_map(char *path)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->n_cols = count_cols(path);
	map->n_rows = count_rows(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	map->board = malloc_board(map->n_rows, map->n_cols);
	create_board(map, path);
	
	close(fd);
	return (map);
}
