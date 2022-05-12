/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:26:39 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 11:26:09 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"

int	ft_error(int n)
{
	if (n == FD_ERR)
		ft_printf("Error\n%s", FD_ERR_MSG);
	else if (n == PARSE_MAP_ERR)
		ft_printf("Error\n%s", PARSE_MAP_ERR_MSG);
	else if (n == MAP_NAME_ERR)
		ft_printf("Error\n%s", MAP_NAME_ERR_MSG);
	else if (n == MALLOC_ERR)
		ft_printf("Error\n%s", MALLOC_ERR_MSG);
	else if (n == EMPTY_FILE_ERR)
		ft_printf("Error\n%s", EMPTY_FILE_ERR_MSG);
	else if (n == NOT_RECT_ERR)
		ft_printf("Error\n%s", NOT_RECT_ERR_MSG);
	else if (n == UNKNOWN_TILE_ERR)
		ft_printf("Error\n%s", UNKNOWN_TILE_ERR_MSG);
	else if (n == WALL_ERR)
		ft_printf("Error\n%s", WALL_ERR_MSG);
	else if (n == MIN_ERR)
		ft_printf("Error\n%s", MIN_ERR_MSG);
	return (0);
}
