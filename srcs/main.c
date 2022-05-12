/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:10:16 by afaby             #+#    #+#             */
/*   Updated: 2022/05/11 16:10:58 by afaby            ###   ########.fr       */
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
	t_env		env;
	t_player	player;
	t_texture	texture;

	(void)argc;
	init_env(&env, argv[1]);
	charge_texture(&env, &texture);
	init_player(&env, &player);
	env.t = &texture;
	env.player = &player;
	print_water(&env);
	render(&env);
	mlx_hook(env.win, DestroyNotify, StructureNotifyMask, &quit, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, &key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
