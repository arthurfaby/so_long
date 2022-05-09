/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:06:05 by afaby             #+#    #+#             */
/*   Updated: 2022/05/09 16:42:21 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

t_tile	*create_tile(char, int, int);
int		create_board(t_map *, char *);
t_map	*create_map(char *);
t_tile	***malloc_board(int	, int);
void	charge_texture(t_env *, t_texture *);
void	init_player(t_env *, t_player *);
int		key_hook(int, t_env *);
int		render(t_env *);
void	print_water(t_env *);
void	print_player(t_env *);
void	print_tile(t_env *, int, int);
void	open_exit(t_env *);
int		render(t_env *);
void	display_health(t_env *);
void	display_progression(t_env *);
void	img_pixel_put(t_env *, t_image *, int, int, int);
void	display_menu(t_env *);
int		ft_error(int);
void	end_game(t_env *, int);
int		check_rect(char *);
int		quit(t_env *env);
#endif
