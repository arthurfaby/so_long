/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:11:15 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 18:27:46 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "defines.h"

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
}	t_map;

typedef struct	s_texture
{
	void	*water;
	void	*ground;
	void	*spawn;
	void	*exit;
	void	*collectable;
	void	*collected;
	void	*bn;
	void	*bs;
	void	*be;
	void	*bw;
	void	*bne;
	void	*bnw;
	void	*bse;
	void	*bsw;
}	t_texture;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_map		*map;
	t_texture	*texture;
}	t_env;

#endif
