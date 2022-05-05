/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:26:16 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 17:53:27 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BUFFER_SIZE 1

# define ABS(x) x < 0 ? -x : x
# define MAX(a, b) a < b ? b : a
# define MIN(a, b) a < b ? a : b
# define RGB(r, g, b) ((((r) << 8) + (g)) << 8) + (b)

# define WATER 1
# define GROUND 2
# define SPAWN 3
# define EXIT 4
# define COLLECTABLE 5
# define BORDER_N 6
# define BORDER_S 7
# define BORDER_E 8
# define BORDER_W 9
# define BORDER_NE 10
# define BORDER_NW 11
# define BORDER_SE 12
# define BORDER_SW 13

# define TEXTURE_DEFINITION 16

#endif
