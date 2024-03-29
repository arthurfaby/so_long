/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:11:15 by afaby             #+#    #+#             */
/*   Updated: 2022/05/19 11:10:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "defines.h"

typedef struct s_tile
{
	int	row;
	int	col;
	int	width;
	int	height;
	int	type;
}	t_tile;

typedef struct s_map
{
	t_tile	***board;
	int		n_cols;
	int		n_rows;
	int		to_collect;
}	t_map;

typedef struct s_player
{
	int	row;
	int	col;
	int	collected;
	int	moves;
}	t_player;

typedef struct s_image
{
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
	void	*img;
}	t_image;

typedef struct s_texture
{
	void	*water;
	void	*ground;
	void	*spawn;
	void	*exit_on;
	void	*exit_off;
	void	*collectible;
	void	*collected;
	void	*wall;
	void	*no_texture;
	void	*player;
	void	*player2;
	void	*player3;
	void	*title;
	void	*title_play;
}	t_texture;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			in_menu;
	int			selected;
	t_map		*map;
	t_texture	*t;
	t_player	*player;
}	t_env;

#endif
