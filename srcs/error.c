/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:45:45 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 17:36:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "functions.h"
#include "includes.h"

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	return (
		str[len - 1] == 'r'
		&& str[len - 2] == 'e'
		&& str[len - 3] == 'b'
		&& str[len - 4] == '.'
	);
}

int	check_legal_tile(char c)
{
	return (c == '0' || c == '1' || c == 'P'
		|| c == 'E' || c == 'C' || c == 'F' || c == '\n');
}

void	check_content(char *path)
{
	char	*line;
	int		fd;
	int		i;
	int		ok;

	ok = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		end_game(NULL, FD_ERR);
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
		end_game(NULL, EMPTY_FILE_ERR);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (!check_legal_tile(line[i]))
				ok = 0;
		}
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
	}
	if (!ok)
		end_game(NULL, UNKNOWN_TILE_ERR);
}

void	check_map(char *path)
{
	check_content(path);
	check_rect(path);
	check_min(path);
}
