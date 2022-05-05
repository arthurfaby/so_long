/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:10:16 by afaby             #+#    #+#             */
/*   Updated: 2022/05/05 21:56:02 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "defines.h"
#include "structures.h"
#include "libft.h"
#include "mlx.h"

void	print_tile(t_env *env, int x, int y)
{
	if (env->map->board[x][y]->type == GROUND)
		mlx_put_image_to_window(env->mlx, env->win, env->texture->ground, x * 16, y * 16);
	else
		mlx_put_image_to_window(env->mlx, env->win, env->texture->water, x * 16, y * 16);
}

int	render(t_env *env)
{
	int	x;
	int	y;

	x = 2;
	if (env->win)
	{
		while (env->map->board[x])
		{
			y = 0;
			while (env->map->board[x][y])
			{
				print_tile(env, x, y);
				y++;
			}
			x++;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	
	t_env		env;
	t_texture	texture;

	env.map = create_map(argv[1]);
	env.mlx = mlx_init();
	env.width = 500;
	env.height = 500;
	env.win = mlx_new_window(env.mlx, env.width, env.height, "SO_COOL");
	charge_texture(&env, &texture);
	env.texture = &texture;
	ft_printf("\033[0;32mMap successfully created !\n");
	//ft_printf("\033[0;33mn_rows : %d, n_cols : %d\n", env.map->n_rows, env.map->n_cols);

	//ft_printf("Value : %d\n", env.map->board[5][9]->type);
	mlx_loop_hook(env.mlx, &render, &env);
	mlx_loop(env.mlx);
	return (0);
}
