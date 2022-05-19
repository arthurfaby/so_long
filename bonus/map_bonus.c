/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:34:03 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 11:25:49 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_cols(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		end_game(NULL, FD_ERR);
	}
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
	{
		free(map);
		end_game(NULL, EMPTY_FILE_ERR);
	}
	close(fd);
	len = ft_strlen(line);
	free(line);
	return (len - 1);
}

int	count_rows(char *path, t_map *map)
{
	int		fd;
	int		n_rows;
	char	*line;

	fd = open(path, O_RDONLY);
	n_rows = 0;
	if (fd == -1)
	{
		free(map);
		end_game(NULL, FD_ERR);
	}
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
	{
		free(map);
		end_game(NULL, EMPTY_FILE_ERR);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
		n_rows++;
	}
	close(fd);
	return (n_rows);
}

int	count_collectable(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int		count;
	int		i;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		end_game(NULL, FD_ERR);
	}
	line = get_next_line(fd, BUFFER_SIZE);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'C')
				count++;
		}
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
	}
	return (count);
}

t_map	*create_map(char *path)
{
	t_map	*map;
	int		fd;

	check_map(path);
	map = malloc(sizeof(t_map));
	if (!map)
		end_game(NULL, MALLOC_ERR);
	map->n_cols = count_cols(path, map);
	map->n_rows = count_rows(path, map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		end_game(NULL, FD_ERR);
	}
	map->board = malloc_board(map->n_rows, map->n_cols);
	create_board(map, path);
	map->to_collect = count_collectable(path, map);
	close(fd);
	check_wall(map);
	return (map);
}
