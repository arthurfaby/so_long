/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:10:16 by afaby             #+#    #+#             */
/*   Updated: 2022/05/10 09:46:02 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "defines.h"
#include "structures.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"


int	main(int argc, char *argv[])
{
	(void)argc;
	t_env		env;
	t_player	player;
	t_texture	texture;

	env.map = create_map(argv[1]);
	env.mlx = mlx_init();
	env.width = (env.map->n_cols + 8) * 16;
	if (env.width < 800)
		env.width = 800;
	env.height = (env.map->n_rows + 8) * 16;
	if (env.height < 500)
		env.height = 500;
	env.win = mlx_new_window(env.mlx, env.width, env.height, "SO_COOL");
	env.in_menu = 1;
	env.selected = 1;
	charge_texture(&env, &texture);
	init_player(&env, &player);
	env.texture = &texture;
	env.player = &player;
	print_water(&env);
	render(&env);
	mlx_hook(env.win, DestroyNotify, StructureNotifyMask, &quit, &env);	
	mlx_hook(env.win, KeyPress, KeyPressMask, &key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
