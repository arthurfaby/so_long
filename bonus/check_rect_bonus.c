/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:19:43 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 11:25:59 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	modif_ok(char *line, size_t len, int ok)
{
	if (ft_strchr(line, '\n'))
	{
		if (len != ft_strlen(line))
			return (1);
	}
	else if (len - 1 != ft_strlen(line))
		return (1);
	return (ok);
}

void	check_rect(char *path)
{
	char	*line;
	size_t	len;
	int		fd;
	int		ok;

	ok = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		end_game(NULL, FD_ERR);
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
		end_game(NULL, EMPTY_FILE_ERR);
	len = ft_strlen(line);
	while (line)
	{
		ok = modif_ok(line, len, ok);
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
	}
	if (ok)
		end_game(NULL, NOT_RECT_ERR);
}
