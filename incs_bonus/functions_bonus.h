/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:06:05 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 17:35:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_BONUS_H
# define FUNCTIONS_BONUS_H

# include "structures_bonus.h"
# include "includes_bonus.h"

// BOARD.C

t_tile	***malloc_board(int n_rows, int n_cols);
int		create_board(t_map *map, char *path);

// CHECK_WALL.C

void	check_top(t_map *map);
void	check_bot(t_map *map);
void	check_left(t_map *map);
void	check_right(t_map *map);
void	check_wall(t_map *map);

// DISPLAY.C

void	print_water(t_env *env);
void	print_water_banner(t_env *env);
void	print_tile(t_env *env, int x, int y);
void	print_player(t_env *env);
void	print_moves(t_env *env);

// RENDER.C

int		render(t_env *env);

// END.C

void	free_texture(t_env *env);
void	free_map(t_map *map);
void	end_game(t_env *env, int code);
int		quit(t_env *env);

// ERROR.C

int		check_legal_tile(char c);
void	check_content(char *path);
void	check_map(char *path);
int		check_extension(char *str);

// PRINT.C

int		ft_error(int n);

// IMAGE.C

void	img_pixel_put(t_image *img, int y, int x, int color);

// INTERFACE.C

void	display_progression(t_env *env);
void	display_health(t_env *env);

// KEY.C

int		check_moves(int keycode, t_env *env);
int		key_hook(int keycode, t_env *env);

// MAP.C

int		count_cols(char *path, t_map *map);
int		count_rows(char *path, t_map *map);
int		count_collectable(char *path, t_map *map);
t_map	*create_map(char *path);

// MENU.C

void	display_menu(t_env *env);

// PLAYER.C

void	init_player(t_env *env, t_player *player);

// TEXTURE.C

void	charge_texture_menu(t_env *env, t_texture *t);
void	charge_texture_entity(t_env *env, t_texture *t);
void	charge_texture_struct(t_env *env, t_texture *t);
void	charge_texture(t_env *env, t_texture *t);

// TILE.C

int		choose_type(char type);
t_tile	*create_tile(char typ, int row, int col);

// UPDATE.C

void	open_exit(t_env *env);

// MOVES.C

void	check_modif(t_env *env);
void	move_right(t_env *env);
void	move_left(t_env *env);
void	move_top(t_env *env);
void	move_bottom(t_env *env);

// ENV.C

void	init_env(t_env *env, char *path);

// CHECK_MIN.C

void	check_min(char *path);
void	set_code(char c, int *code);

// MOVE_ENEMY.C

void	move_enemies(t_env *env);
void	move_enemy_left(t_env *env, int x, int y);
void	move_enemy_right(t_env *env, int x, int y);
void	move_enemy_bot(t_env *env, int x, int y);
void	move_enemy_top(t_env *env, int x, int y);

// CHECK_RECT.C

int		modif_ok(char *line, size_t len, int ok);
void	check_rect(char *path);

#endif
