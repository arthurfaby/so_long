/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:26:16 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 10:58:34 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BUFFER_SIZE 1

# define ABS(x) x < 0 ? -x : x
# define MAX(a, b) a < b ? b : a
# define MIN(a, b) a < b ? a : b
# define RGB(r, g, b) ((((r) << 8) + (g)) << 8) + (b)

// SPRITES

# define WALL 1
# define GROUND 2
# define SPAWN 3
# define EXIT_ON 4
# define EXIT_OFF 5
# define COLLECTIBLE 6
# define COLLECTED 7
# define ENEMY 8
# define NO_TEXTURE 15

// ERRORS

# define FD_ERR 128
# define FD_ERR_MSG "\033[0;31m --> can't open file.\n"
# define PARSE_MAP_ERR 129
# define PARSE_MAP_ERR_MSG "\033[0;31m --> unknown character while parsing.\n"
# define MAP_NAME_ERR 130
# define MAP_NAME_ERR_MSG "\033[0;31m --> maps must end in .ber.\n"
# define MALLOC_ERR 131
# define MALLOC_ERR_MSG "\033[0;31m --> malloc return \033[0;33mNULL\033[0;31m.\n"
# define EMPTY_FILE_ERR 132
# define EMPTY_FILE_ERR_MSG "\033[0;31m --> map file is empty.\n"
# define NOT_RECT_ERR 133
# define NOT_RECT_ERR_MSG "\033[0;31m --> map must be rectangular.\n"
# define UNKNOWN_TILE_ERR 134
# define UNKNOWN_TILE_ERR_MSG "\033[0;31m --> unknown tile.\n"
# define WALL_ERR 135
# define WALL_ERR_MSG "\033[0;31m --> map must be surronded by walls.\n"
# define MIN_ERR 136
# define MIN_ERR_MSG "\033[0;31m --> at least 1 P, 1 E and 1 C in the map.\n"
#endif
