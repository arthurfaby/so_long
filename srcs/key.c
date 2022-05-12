/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:26:59 by afaby             #+#    #+#             */
/*   Updated: 2022/05/12 14:41:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "functions.h"
#include "mlx_int.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		end_game(env, -1);
	if (env->in_menu)
	{
		if (keycode == XK_Return && env->selected == 1)
		{
			env->in_menu = 0;
			print_water(env);
			render(env);
		}
	}
	else if (!env->in_menu)
	{
		if (keycode == 'w')
			move_top(env);
		else if (keycode == 's')
			move_bottom(env);
		else if (keycode == 'a')
			move_left(env);
		else if (keycode == 'd')
			move_right(env);
	}
	return (0);
}
