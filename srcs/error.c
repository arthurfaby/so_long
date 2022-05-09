/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:17:06 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 16:49:46 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "functions.h"
#include "includes.h"

int	check_rect(char *path)
{
	char	*line;
	size_t	len;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		end_game(NULL, FD_ERR);
	line = get_next_line(fd, BUFFER_SIZE);
	if (!line)
		end_game(NULL, EMPTY_FILE_ERR);
	len = ft_strlen(line);
	while (line)
	{
		if (ft_strchr(line, '\n'))
		{
			if (len != ft_strlen(line))
			{
				free(line);
				return (0);
			}
		}
		else if (len - 1 != ft_strlen(line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd, BUFFER_SIZE);
	}
	return (1);
}
/*
int	check_map(char *path)
{
	check_rect(path);
}*/

int	ft_error(int n)
{
	if (n == FD_ERR)
		ft_printf("%s", FD_ERR_MSG);
	else if (n == PARSE_MAP_ERR)
		ft_printf("%s", PARSE_MAP_ERR_MSG);
	else if (n == MAP_NAME_ERR)
		ft_printf("%s", MAP_NAME_ERR_MSG);
	else if (n == MALLOC_ERR)
		ft_printf("%s", MALLOC_ERR_MSG);
	else if (n == EMPTY_FILE_ERR)
		ft_printf("%s", EMPTY_FILE_ERR_MSG);
	else if (n == NOT_RECT_ERR)
		ft_printf("%s", NOT_RECT_ERR_MSG);
	return (0);
}
