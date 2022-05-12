/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:13:47 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 11:22:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "libft.h"
#include "includes.h"

void	set_code(char c, int *code)
{
	if (c == 'P')
		*code |= 1;
	if (c == 'E')
		*code |= 2;
	if (c == 'C')
		*code |= 4;
}

void	check_min(char *path)
{
	int		code;
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		end_game(NULL, FD_ERR);
	code = 0;
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
		end_game(NULL, EMPTY_FILE_ERR);
	while (line)
	{
		i = -1;
		while (line[++i])
			set_code(line[i], &code);
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
	}
	if (code != 7)
		end_game(NULL, MIN_ERR);
}
